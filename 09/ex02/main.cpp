#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

static void printSeq(const std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << " ";
        std::cout << v[i];
    }
}
//static void printSeq(const std::deque<int>& d) {
//    for (size_t i = 0; i < d.size(); ++i) {
//        if (i) std::cout << " ";
//        std::cout << d[i];
//    }
//}

int main(int argc, char** argv) {
    try {
        std::vector<int> input = PmergeMe::parseArgs(argc, argv);
        if (input.empty()) { std::cerr << "Error" << std::endl; return 1; }

        // Before
        std::cout << "Before: ";
        printSeq(input);
        std::cout << std::endl;

        // Prepare both containers
        std::vector<int> v = input;
        std::deque<int>  d(input.begin(), input.end());

        // Time + sort
        double tVec = PmergeMe::timeVectorSort(v);
        double tDeq = PmergeMe::timeDequeSort(d);

        // After (mostrar el de uno de ellos; deben coincidir)
        std::cout << "After:  ";
        printSeq(v);
        std::cout << std::endl;

        // Tiempos (formato libre pero “claro”, dice el subject)
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << input.size()
                  << " elements with std::vector : " << tVec << " us" << std::endl;
        std::cout << "Time to process a range of " << input.size()
                  << " elements with std::deque  : " << tDeq << " us" << std::endl;
    } catch (const std::exception&) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
