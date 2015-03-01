#include <iostream>
#include "CompileToBash.h"
#include "Parser.h"

void compile_to_bash(std::ostream &os, Bish::AST *ast) {
    Bish::CompileToBash compile(os);
    ast->accept(&compile);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "USAGE: " << argv[0] << " <INPUT>\n";
        std::cerr << "  Compiles Bish file <INPUT> to bash.\n";
        return 1;
    }
    
    std::string path(argv[1]);
    Bish::Parser p;
    Bish::AST *ast = p.parse(path);

    compile_to_bash(std::cout, ast);
    
    return 0;
}