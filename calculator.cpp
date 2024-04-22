#include <iostream>
#include <string>
#include "calculator_lexer.h"
#include "calculator_parser.h"
#include "ref_env.h"
#include <fstream>

int main(int argc, char *argv[]) {
    CalculatorLexer lexer;
    CalculatorParser parser;
    std::string linebuffer;
    RefEnv global;

    if (argc == 2) {
        std::ifstream fileStreamObj;
        fileStreamObj.open(argv[1]);
        if (!fileStreamObj.is_open()) {
            std::cerr << "Error: Enter Correct FileName Unable to process the current file\n";
            return 1;
        }
        while (std::getline(fileStreamObj, linebuffer)) {           
            lexer.input(linebuffer);
            ASTNode *tree = parser.parse(&lexer);
            ASTResult result = tree->eval(&global);
            delete tree;
        }
        fileStreamObj.close();

    } else {
        for (;;) {
            // get a line of input
            std::cout << "> ";
            std::getline(std::cin, linebuffer);
            if (!std::cin) break;

            // set the input string to scan
            lexer.input(linebuffer);
            ASTNode *tree = parser.parse(&lexer);
            ASTResult result = tree->eval(&global);
            delete tree;

            // print the result
            if (result.type == ASTResult::INT) {
                std::cout << result.value.i << std::endl;
            } else if (result.type == ASTResult::REAL) {
                std::cout << result.value.r << std::endl;
            }
        }
    }
    return 0;
}