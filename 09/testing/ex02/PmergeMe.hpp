#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <climits>
#include <sys/time.h>

class PmergeMe {
public:
    // Canonical Orthodox (vacía)
    PmergeMe();
    PmergeMe(const PmergeMe&);
    PmergeMe &operator=(const PmergeMe&);
    ~PmergeMe();

    // API
    static bool isPositiveInteger(const std::string &s);
    static void run(int argc, char** argv);

private:
    // Parseo
    static int parseOne(const std::string &s);

    template <typename Seq>
    static Seq parseAll(int argc, char** argv);

    // Ford–Johnson (Merge-Insert) para vector y deque
    static void fordJohnson(std::vector<int> &a);
    static void fordJohnson(std::deque<int> &a);

    // Implementación genérica interna (iteradores aleatorios) ocultada tras las dos públicas
    template <typename Seq>
    static void fj_impl(Seq &a);

    // Utilidades de Ford–Johnson
    template <typename T> struct Pair { T big; T small; };

    template <typename Seq>
    static void makePairs(const Seq &in,
                          std::vector< Pair<typename Seq::value_type> > &pairs,
                          bool &hasOdd,
                          typename Seq::value_type &odd);

    template <typename T>
    static std::vector<T> extractBigs(const std::vector< Pair<T> > &pairs);

    template <typename T>
    static std::vector<T> extractSmallsReordered(const std::vector< Pair<T> > &pairs,
                                                 const std::vector<T> &sortedBigs);

    template <typename Seq, typename T>
    static typename Seq::iterator binInsert(Seq &mainChain, const T &value,
                                            size_t left, size_t rightExclusive);

    static std::vector<size_t> buildJacobsthalOrder(size_t n);

    // Medición de tiempo
    static double elapsed_us(const timeval &t0, const timeval &t1);
};

#endif
