#include "ast.h"
#include "environment.h"
#include <boost/regex.hpp>
#include <iostream>

/**
 * @brief Interpreter for executing the AST
 */
class Interpreter {
    /**
     * @brief root node of the AST
     */
    TransUnit *root;
    /**
     * @brief Every section has its own environment, so this is a map from
     * section to environment
     */
    std::unordered_map<Section *, Environment> envs;
    /**
     * @brief an index from section name to section
     */
    std::unordered_map<std::string, Section *> nodes;
    /**
     * @brief this is used to store the previous node, so that we can use $prev
     * in the next node
     */
    Section *prev = nullptr;

  public:
    Interpreter(TransUnit *root) : root(root) {}
    /**
     * @brief  Initialize the environment
     */
    void init_env() {
        for (auto &section : root->sections) {
            envs[section.get()] = Environment();
            nodes[section->name] = section.get();
        }
    }
    /**
     * @brief Interpret the AST
     */
    void interpret() {
        init_env();
        prev = nullptr;
        auto curNode = root->sections[0].get();
        Section *nextNode;
        auto interpret_node_with_retry = [&]() {
            try {
                nextNode = interpret_node(curNode);
            } catch (const std::exception &e) {
                std::cerr
                    << "Encounter some error, please retry. detail: error at "
                    << e.what() << '\n';
                nextNode = curNode;
            }
        };
        interpret_node_with_retry();
        while (nextNode) {
            prev = curNode;
            curNode = nextNode;
            interpret_node_with_retry();
        }
    }
    // pair: the uncond node , should terminate or not
    std::pair<Section *, bool> find_uncond_node(Section *node) {
        auto trans = node->get_subsection("Trans");
        for (auto &&kv : trans->properties) {
            auto key = kv.first;
            auto value = kv.second.get();
            if (auto *idExpr = dynamic_cast<IDExpr *>(value)) {
                Section *ret = nullptr;
                if (key == "$prev") {
                    ret = prev;
                } else if (key == "$term") {
                    ret = nullptr;
                } else {
                    ret = nodes[key];
                }
                if (idExpr->value == "uncond") {
                    return {ret, key == "$term"};
                }
            }
        }
        return {nullptr, false};
    }
    Section *interpret_node(Section *node) {
        auto hint = node->get_subsection("Hint");
        std::string enterHint;
        if (hint) {
            enterHint = to_print(&(envs[node]), hint->get_prop("enter"));
            std::cout << enterHint << std::endl;
        }
        // if has uncond node, go to it
        Section *uncondNode;
        bool term;
        std::tie(uncondNode, term) = find_uncond_node(node);
        if (term) {
#ifdef DEBUG
            printf("[DEBUG] terminating\n");
#endif
            return nullptr;
        }
        if (uncondNode) {
#ifdef DEBUG
            printf("[DEBUG] found uncond node: %s\n", uncondNode->name.c_str());
#endif
            return uncondNode;
        }
        if (!enterHint.empty()) {
            std::string input;
            std::cin >> input;
            envs[node].set("$input", input);
        }
        if (auto storage = node->get_subsection("Storage")) {
            for (auto &&kv : storage->properties) {
                auto id = kv.first;
                auto expr = kv.second.get();
                auto &&ev = envs[node];
                ev.set(id, eval_expr(&ev, expr));
            }
        }

        auto trans = node->get_subsection("Trans");
        Expr *matchCond = nullptr;
        Section *ret = nullptr; // matchNode
        for (auto &&kv : trans->properties) {
            auto key = kv.first;
            auto value = kv.second.get();
            if (eval_expr(&(envs[node]), value) == ER_True) {
                matchCond = value;
                if (key == "$prev") {
                    ret = prev;
                } else if (key == "$term") {
                    ret = nullptr;
                } else {
                    // check if key is in nodes
                    if (nodes.find(key) == nodes.end()) {
                        std::cerr << "No such node: " << key << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    ret = nodes[key];
                }
                break;
            }
        }
        if (nullptr == ret) {
            std::cerr << "Nothing to do with your input, please retry"
                      << std::endl;
            return node;
        }
#ifdef DEBUG
        printf("[DEBUG] %s is true, next is %s\n",
               matchCond->to_string().c_str(), ret->name.c_str());
#endif
        return ret;
    }

    /**
     * @brief Evaluate an expression
     * Allowing types:
     * + BinOpExpr
     * + UnaryExpr
     * + CallExpr
     * + IDExpr
     * + NumberExpr
     * + StringExpr
     */
    EvalResult eval_expr(Environment *env, Expr *expr) {
        if (auto binOp = dynamic_cast<BinOpExpr *>(expr)) {
            auto lhs = eval_expr(env, binOp->lhs.get());
            auto rhs = eval_expr(env, binOp->rhs.get());
            auto op = binOp->op;
            if (op == "eq") {
                return EvalResult(lhs.str_val == rhs.str_val);
            } else if (op == "+") {
                return EvalResult(lhs.num_val + rhs.num_val);
            } else if (op == "-") {
                return EvalResult(lhs.num_val - rhs.num_val);
            } else if (op == "*") {
                return EvalResult(lhs.num_val * rhs.num_val);
            } else if (op == "/") {
                return EvalResult(lhs.num_val / rhs.num_val);
            } else if (op == "%") {
                return EvalResult(
                    static_cast<double>(static_cast<int>(lhs.num_val) %
                                        static_cast<int>(rhs.num_val)));
            } else if (op == "and") {
                return EvalResult(lhs.bool_val && rhs.bool_val);
            } else if (op == "or") {
                return EvalResult(lhs.bool_val || rhs.bool_val);
            } else if (op == ">") {
                return EvalResult(lhs.num_val > rhs.num_val);
            } else if (op == "<") {
                return EvalResult(lhs.num_val < rhs.num_val);
            } else if (op == ">=") {
                return EvalResult(lhs.num_val >= rhs.num_val);
            } else if (op == "<=") {
                return EvalResult(lhs.num_val <= rhs.num_val);
            } else if (op == "ne") {
                return EvalResult(lhs.num_val != rhs.num_val);
            } else {
                std::cerr << "unknown op: " << op << std::endl;
                exit(EXIT_FAILURE);
            }
        } else if (auto unary = dynamic_cast<UnaryExpr *>(expr)) {
            auto val = eval_expr(env, unary->expr.get());
            if (unary->op == "not") {
                return EvalResult(!val.bool_val);
            } else {
                std::cerr << "unknown op: " << unary->op << std::endl;
            }
        } else if (auto call = dynamic_cast<CallExpr *>(expr)) {
            if (call->name == "print") {
                for (auto &&arg : call->args) {
                    auto val = eval_expr(env, arg.get());
                    std::cout << val.str_val;
                }
                std::cout << std::endl;
            }
            if (call->name == "str2num") {
                auto val = eval_expr(env, call->args[0].get());
                return EvalResult(std::stod(val.str_val));
            }
            if (call->name == "load") {
                auto val = eval_expr(env, call->args[0].get());
                return EvalResult(envs[prev].get(val.str_val));
            }
        } else if (auto id = dynamic_cast<IDExpr *>(expr)) {
            auto val = env->get(id->value);
            return val;
        } else if (auto num = dynamic_cast<NumberExpr *>(expr)) {
            return EvalResult(num->value);
        } else if (auto str = dynamic_cast<StringExpr *>(expr)) {
            return EvalResult(str->value);
        }
        assert(false);
        return EvalResult();
    }

    /**
     * @brief Print a string even with {func('param')} in it
     */
    std::string to_print(Environment *env, Expr *expr) {
        if (nullptr == expr) {
            return std::string();
        }
        auto ret = std::string();
        if (auto str = dynamic_cast<StringExpr *>(expr)) {
            ret = str->value;
            auto static re = boost::regex("\\{(\\w+)\\('(\\w+)'\\)\\}");
            ret = boost::regex_replace(ret, re, [&](const boost::smatch &m) {
                auto id = m[1].str();
                auto param = m[2].str();
                auto call = CallExpr();
                call.name = id;
                call.args.push_back(std::make_unique<StringExpr>(param));
                return eval_expr(env, &call).to_string();
            });
        }
        return ret;
    }
};