#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>    // clock()
#include <cstddef>  // size_t

class PmergeMe {
public:
    // Entrada: argv -> valida y convierte a enteros positivos
    static std::vector<int> parseArgs(int argc, char** argv);

    // Ordenaciones separadas (recomendación del subject)
    static void sortVector(std::vector<int>& v);
    static void sortDeque(std::deque<int>& d);

    // Utils para medir tiempo en microsegundos (C++98)
    static double timeVectorSort(std::vector<int> v);
    static double timeDequeSort(std::deque<int> d);

private:
    // --- Implementación Ford-Johnson (Merge-Insertion) para vector ---
    static void fordJohnsonVector(std::vector<int>& a);

    // --- Implementación Ford-Johnson (Merge-Insertion) para deque ---
    static void fordJohnsonDeque(std::deque<int>& a);

    // Secuencia de Jacobsthal para ordenar inserciones
    static std::vector<size_t> jacobsthalOrder(size_t n);

    // Inserción binaria en contenedores (versiones separadas)
    static void binaryInsert(std::vector<int>& sorted, int value);
    static void binaryInsert(std::deque<int>&  sorted, int value);

    // Helpers
    static bool isPositiveInteger(const std::string& s);
};

#endif
