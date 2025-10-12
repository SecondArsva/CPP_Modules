#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange instance;
    instance.loadDatabase(); // intenta cargar cpp_09/data.csv o data.csv
    instance.processInputFile(argv[1]);
    return 0;
}
