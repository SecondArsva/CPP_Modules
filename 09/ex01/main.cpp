#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    RPN rpn;
    long res = 0;
    if (!rpn.evaluate(std::string(argv[1]), res)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << res << std::endl;
    return 0;
}
