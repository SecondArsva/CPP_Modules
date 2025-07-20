#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5

int main() {
    Array<int> numbers(MAX_VAL);

    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = i * 10;

    for (int i = 0; i < MAX_VAL; i++)
        std::cout << "numbers["<<i<<"]("<< &numbers[i] <<"): " << numbers[i] << std::endl;

    std::cout << "Size: " << numbers.size() << std::endl;

    // Test de copia
    Array<int> copy(numbers);
    copy[0] = 999;

    std::cout << "After modifying copy:" << std::endl;
    std::cout << "copy[0]("<< &copy[0] <<"): " << copy[0] << std::endl;
    std::cout << "numbers[0]("<< &numbers[0] <<"): " << numbers[0] << std::endl;

    // Test de excepción
    try {
        std::cout << numbers[MAX_VAL] << std::endl; // fuera de rango
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
