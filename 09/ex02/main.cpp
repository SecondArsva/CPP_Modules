#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

static void printSequence(const char* prefix, const std::vector<int>& v)
{
    std::cout << prefix;
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    PmergeMe pm;

    std::vector<int> input;
    if (!pm.parseArgs(argc, argv, input)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // Before
    printSequence("Before: ", input);

    // Copias para cada contenedor
    std::vector<int> v(input.begin(), input.end());
    std::deque<int>  d(input.begin(), input.end());

    // ---- Vector ----
    std::clock_t startVec = std::clock();
    pm.sortVector(v);
    std::clock_t endVec = std::clock();

    // ---- Deque ----
    std::clock_t startDeq = std::clock();
    pm.sortDeque(d);
    std::clock_t endDeq = std::clock();

    // After (usamos el vector)
    printSequence("After:  ", v);

    // Tiempos
    double usVec = 1e6 * (double)(endVec - startVec) / (double)CLOCKS_PER_SEC;
    double usDeq = 1e6 * (double)(endDeq - startDeq) / (double)CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << usVec << " us" << std::endl;

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque  : "
              << std::fixed << std::setprecision(5) << usDeq << " us" << std::endl;

    return 0;
}
