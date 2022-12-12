#pragma once
#include <boost/algorithm/string/replace.hpp>
#include <string>

#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct Expr {
    virtual std::string to_string() const = 0;
};

enum ValType {
    ValType_STRING = 0,
    ValType_NUMBER = 1,
    ValType_BOOL = 2,
    ValTypeCount
};
struct EvalResult {
    ValType type;
    std::string str_val{""};
    double num_val{0.0};
    bool bool_val{false};
    EvalResult() {}
    EvalResult(std::string str_val) : type(ValType_STRING), str_val(str_val) {}
    EvalResult(double num_val) : type(ValType_NUMBER), num_val(num_val) {}
    EvalResult(bool bool_val) : type(ValType_BOOL), bool_val(bool_val) {}

    bool operator==(const EvalResult &other) const {
        if (type != other.type) {
            return false;
        }
        switch (type) {
        case ValType_STRING:
            return str_val == other.str_val;
        case ValType_NUMBER:
            return num_val == other.num_val;
        case ValType_BOOL:
            return bool_val == other.bool_val;
        }
        return false;
    }

    std::string to_string() const {
        switch (type) {
        case ValType_STRING:
            return str_val;
        case ValType_NUMBER:
            return std::to_string(num_val);
        case ValType_BOOL:
            return bool_val ? "true" : "false";
        }
        return "";
    }
};
const static EvalResult ER_True = EvalResult(true);
const static EvalResult ER_False = EvalResult(false);
const static EvalResult ER_Zero = EvalResult(0.0);

/**
 * All operations:
 * "or"
 * "and"
 * "eq"
 * "ne"
 * ">"
 * "<"
 * ">="
 * "<="
 * "+"
 * "-"
 * "*"
 * "/"
 * "("
 * ")"
 * ","
 */

struct Subsection {
    std::string name;
    std::vector<std::pair<std::string, std::unique_ptr<Expr>>> properties;

    std::string to_string() const {
        std::string ret = "\"" + name + "\": {";
        int i = 0;
        for (auto &kv : properties) {
            ret += "\"" + kv.first + "\": " + kv.second->to_string() + "";
            if (i != properties.size() - 1) {
                ret += ",";
            }
            i++;
        }
        ret += "}";
        return ret;
    }

    Expr *get_prop(std::string key) {
        for (auto &&pair : properties) {
            if (pair.first == key)
                return pair.second.get();
        }
        return nullptr;
    }
};

struct Section {
    std::string name;
    std::vector<std::unique_ptr<Subsection>> subsections;
    Section() {}
    Section(std::string name) : name(name) {}
    std::string to_string() const {
        std::string ret = "\"" + name + "\": {";
        for (int i = 0; i < subsections.size(); i++) {
            ret += subsections[i]->to_string();
            if (i != subsections.size() - 1) {
                ret += ", ";
            }
        }
        ret += "}";
        return ret;
    }

    Subsection *get_subsection(const std::string &name) {
        for (auto &sub : subsections) {
            if (sub->name == name) {
                return sub.get();
            }
        }
        return nullptr;
    }
};

struct TransUnit {
    std::vector<std::unique_ptr<Section>> sections;

    std::string to_string() const {
        std::string ret = "{";
        for (int i = 0; i < sections.size(); i++) {
            ret += sections[i]->to_string();
            if (i != sections.size() - 1) {
                ret += ", ";
            }
        }
        ret += "}";
        return ret;
    }
};

struct BinOpExpr : Expr {
    std::unique_ptr<Expr> lhs;
    std::unique_ptr<Expr> rhs;
    std::string op;

    std::string to_string() const {
        return "(" + lhs->to_string() + " " + op + " " + rhs->to_string() + ")";
    }
};
struct UnaryExpr : Expr {
    std::string op;
    std::unique_ptr<Expr> expr;

    std::string to_string() const {
        return "(" + op + " " + expr->to_string() + ")";
    }
};

struct CallExpr : Expr {
    std::string name;
    std::vector<std::unique_ptr<Expr>> args;

    std::string to_string() const {
        std::string ret = name + "(";
        for (int i = 0; i < args.size(); i++) {
            ret += args[i]->to_string();
            if (i != args.size() - 1) {
                ret += ", ";
            }
        }
        ret += ")";
        return ret;
    }
};

struct IDExpr : Expr {
    std::string value;

    std::string to_string() const { return value; }
};
struct NumberExpr : Expr {
    double value;
    void set_value(const std::string &str) { value = std::stod(str); }

    std::string to_string() const { return std::to_string(value); }
};
struct StringExpr : Expr {
    std::string value;
    StringExpr() {}
    StringExpr(std::string value) : value(value) {}
    std::string to_string() const {
        std::string s = value;
        boost::replace_all(s, "\n", "\\n");
        return s;
    }
};