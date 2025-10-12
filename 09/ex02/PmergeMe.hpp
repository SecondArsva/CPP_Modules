#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    // Parseo de argumentos a enteros positivos (>0). Devuelve false en error.
    bool parseArgs(int argc, char** argv, std::vector<int>& outVec) const;

    // Ordena usando Ford–Johnson en std::vector y std::deque.
    void sortVector(std::vector<int>& v) const;
    void sortDeque(std::deque<int>& d) const;

private:
    // ---------- Utilidades comunes ----------
    static bool isAllDigits(const std::string& s);
    static long toLong(const std::string& s, bool& ok);

    // Jacobsthal J(n): 0,1,1,3,5,11,... y orden de inserción para N elementos.
    static void buildJacobsthalOrder(size_t n, std::vector<size_t>& order);

    // ---------- Vector ----------
    static void fjSortVector(std::vector<int>& v);
    static void binaryInsertVector(std::vector<int>& chain, size_t boundIndex, int value);

    // ---------- Deque ----------
    static void fjSortDeque(std::deque<int>& d);
    static void binaryInsertDeque(std::deque<int>& chain, size_t boundIndex, int value);
};

#endif
