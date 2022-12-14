#include "interpreter.h"
#include "parser.tab.hh"
#include "stdlib.h"
#include <functional>

/**
 * parser error handler
 */
void yy::parser::error(const std::string &err) {
    std::cout << "found error: " << err << std::endl;
}

/**
 * Input file handler
 */
extern FILE *yyin;
/**
 * Ref to the root node of the AST
 */
extern std::unique_ptr<TransUnit> root;

/**
 * Manage a heap resource lifetime with RAII
 */
class guard {
    std::function<void()> alloc;
    std::function<void()> dealloc;

  public:
    guard(std::function<void()> alloc, std::function<void()> dealloc)
        : alloc(alloc), dealloc(dealloc) {
        alloc();
    }

    ~guard() { dealloc(); }
};

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 0;
    }
    // load file
    auto filename = argv[1];
    guard g([&]() { yyin = fopen(filename, "r"); },
            [&]() {
                if (yyin != nullptr) {
                    fclose(yyin);
                }});
    // -- check if file is valid
    if (yyin == nullptr) {
        std::cout << "failed to open file: " << filename << std::endl;
        return EXIT_FAILURE;
    }
    // parse
    yy::parser parser;
    auto ret = parser.parse();
    if (ret != 0) {
        std::cout << "parse failed" << std::endl;
        return EXIT_FAILURE;
    }
#ifdef DEBUG
    std::cout << root->to_string() << std::endl;
#endif
    // interpret
    Interpreter interpreter(root.get());
    interpreter.interpret();
    return 0;
}
