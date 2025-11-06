#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <climits>
#include <algorithm> // solo para lower_bound en helpers? -> evitamos: haremos binaria manual
// Nota: El subject permite STL en M08/M09, pero evitamos <algorithm> para mayor control.

static bool strToLong(const std::string& s, long& out) {
    std::istringstream iss(s);
    iss >> out;
    return !iss.fail() && iss.eof();
}

bool PmergeMe::isPositiveInteger(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    // Sin signo explícito, rango [0, ...]
    long v;
    if (!strToLong(s, v)) return false;
    return v > 0 && v <= INT_MAX;
}

std::vector<int> PmergeMe::parseArgs(int argc, char** argv) {
    if (argc < 2) throw std::runtime_error("Error");
    std::vector<int> out;
    out.reserve(argc - 1);
    for (int i = 1; i < argc; ++i) {
        std::string token(argv[i]);
        if (!isPositiveInteger(token))
            throw std::runtime_error("Error");
        long v; strToLong(token, v);
        out.push_back(static_cast<int>(v));
    }
    return out;
}

// Jacobsthal sequence indices for insertion groups.
// We produce an order of indices 1..m (min elements count) that follows Jacobsthal gaps.
// Classic approach: build J(k) until >= m, then enumerate groups (J(k), J(k)-1, ..., J(k-1)+1), etc.
std::vector<size_t> PmergeMe::jacobsthalOrder(size_t m) {
    std::vector<size_t> J;
    // J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    J.push_back(0);
    J.push_back(1);
    while (J.back() < m) {
        size_t n = J.size();
        J.push_back(J[n-1] + 2 * J[n-2]);
    }
    std::vector<size_t> order;
    order.reserve(m);
    // Build insertion order over 1..m
    size_t prev = 1;
    for (size_t k = 2; k < J.size(); ++k) {
        size_t curr = J[k];
        if (curr > m) curr = m;
        // push descending: curr, curr-1, ..., prev
        for (size_t i = curr; i >= prev; --i) {
            order.push_back(i);
            if (i == prev) break;
        }
        prev = J[k] + 1; // next block start will be J(k)+1
        if (prev > m) break;
    }
    // If we didn’t reach m due to bounds, ensure all are present:
    // (This loop will usually be no-op)
    std::vector<bool> seen(m+1, false);
    for (size_t i = 0; i < order.size(); ++i) if (order[i] <= m) seen[order[i]] = true;
    for (size_t i = 1; i <= m; ++i) if (!seen[i]) order.push_back(i);
    return order;
}

// Manual lower_bound for vector<int> (ascending)
static size_t lowerBoundVec(const std::vector<int>& a, int x) {
    size_t lo = 0, hi = a.size();
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (a[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

// Manual lower_bound for deque<int> (ascending)
static size_t lowerBoundDeq(const std::deque<int>& a, int x) {
    size_t lo = 0, hi = a.size();
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (a[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

void PmergeMe::binaryInsert(std::vector<int>& sorted, int value) {
    size_t pos = lowerBoundVec(sorted, value);
    sorted.insert(sorted.begin() + pos, value);
}
void PmergeMe::binaryInsert(std::deque<int>& sorted, int value) {
    size_t pos = lowerBoundDeq(sorted, value);
    sorted.insert(sorted.begin() + pos, value);
}

// Core Ford-Johnson for vector:
// 1) Pair elements; within each pair, make sure first >= second.
// 2) Sort the list of "firsts" (maxima) by value using recursion (on pairs).
// 3) Insert the "seconds" (minima) into the sorted maxima sequence following Jacobsthal order.
void PmergeMe::fordJohnsonVector(std::vector<int>& a) {
    const size_t n = a.size();
    if (n <= 1) return;

    // Step 1: make pairs
    std::vector< std::pair<int,int> > pairs;
    pairs.reserve((n + 1) / 2);
    size_t i = 0;
    for (; i + 1 < n; i += 2) {
        int x = a[i], y = a[i+1];
        if (x < y) std::swap(x, y); // ensure first >= second
        pairs.push_back(std::make_pair(x, y));
    }
    bool hasOdd = (i < n);
    int oddVal = 0;
    if (hasOdd) oddVal = a[i];

    // Step 2: recursively sort by firsts (maxima)
    // Extract maxima
    std::vector<int> maxima;
    maxima.reserve(pairs.size());
    for (size_t k = 0; k < pairs.size(); ++k) maxima.push_back(pairs[k].first);
    fordJohnsonVector(maxima); // recursion on the maxima

    // Reorder pairs to follow sorted maxima order
    // We need to map each max to its pair; duplicates may exist, keep stable usage.
    std::vector< std::pair<int,int> > sortedPairs;
    sortedPairs.reserve(pairs.size());
    std::vector<bool> used(pairs.size(), false);
    for (size_t m = 0; m < maxima.size(); ++m) {
        for (size_t p = 0; p < pairs.size(); ++p) {
            if (!used[p] && pairs[p].first == maxima[m]) {
                sortedPairs.push_back(pairs[p]);
                used[p] = true;
                break;
            }
        }
    }

    // Build initial "chain" with maxima in order
    std::vector<int> chain;
    chain.reserve(n);
    for (size_t k = 0; k < sortedPairs.size(); ++k) chain.push_back(sortedPairs[k].first);

    // Step 3: insert minima following Jacobsthal order
    std::vector<int> minima;
    minima.reserve(sortedPairs.size());
    for (size_t k = 0; k < sortedPairs.size(); ++k) minima.push_back(sortedPairs[k].second);

    std::vector<size_t> order = jacobsthalOrder(minima.size());
    for (size_t idx = 0; idx < order.size(); ++idx) {
        size_t j = order[idx];
        if (j == 0 || j > minima.size()) continue;
        int v = minima[j-1];
        // FJ restricts search to a left-bounded window, but we keep full binary insert; acceptable.
        binaryInsert(chain, v);
    }

    if (hasOdd) binaryInsert(chain, oddVal);

    a.swap(chain);
}

// Same idea for deque
void PmergeMe::fordJohnsonDeque(std::deque<int>& a) {
    const size_t n = a.size();
    if (n <= 1) return;

    std::deque< std::pair<int,int> > pairs;
    size_t i = 0;
    for (; i + 1 < n; i += 2) {
        int x = a[i], y = a[i+1];
        if (x < y) std::swap(x, y);
        pairs.push_back(std::make_pair(x, y));
    }
    bool hasOdd = (i < n);
    int oddVal = 0;
    if (hasOdd) oddVal = a[i];

    // maxima
    std::deque<int> maxima;
    for (size_t k = 0; k < pairs.size(); ++k) maxima.push_back(pairs[k].first);
    fordJohnsonDeque(maxima); // recurse on maxima

    // reorder pairs
    std::deque< std::pair<int,int> > sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    for (size_t m = 0; m < maxima.size(); ++m) {
        for (size_t p = 0; p < pairs.size(); ++p) {
            if (!used[p] && pairs[p].first == maxima[m]) {
                sortedPairs.push_back(pairs[p]);
                used[p] = true;
                break;
            }
        }
    }

    // build chain
    std::deque<int> chain;
    for (size_t k = 0; k < sortedPairs.size(); ++k) chain.push_back(sortedPairs[k].first);

    // minima
    std::deque<int> minima;
    for (size_t k = 0; k < sortedPairs.size(); ++k) minima.push_back(sortedPairs[k].second);

    std::vector<size_t> order = jacobsthalOrder(minima.size());
    for (size_t idx = 0; idx < order.size(); ++idx) {
        size_t j = order[idx];
        if (j == 0 || j > minima.size()) continue;
        int v = minima[j-1];
        binaryInsert(chain, v);
    }

    if (hasOdd) binaryInsert(chain, oddVal);

    a.swap(chain);
}

void PmergeMe::sortVector(std::vector<int>& v) {
    fordJohnsonVector(v);
}
void PmergeMe::sortDeque(std::deque<int>& d) {
    fordJohnsonDeque(d);
}

double PmergeMe::timeVectorSort(std::vector<int> v) {
    std::clock_t start = std::clock();
    fordJohnsonVector(v);
    std::clock_t end = std::clock();
    return (end - start) * 1e6 / CLOCKS_PER_SEC; // microseconds
}

double PmergeMe::timeDequeSort(std::deque<int> d) {
    std::clock_t start = std::clock();
    fordJohnsonDeque(d);
    std::clock_t end = std::clock();
    return (end - start) * 1e6 / CLOCKS_PER_SEC; // microseconds
}
