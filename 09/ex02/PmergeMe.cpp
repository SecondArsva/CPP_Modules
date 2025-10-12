#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <climits>
#include <ctime>
#include <iomanip>

// ------------------ Public ------------------

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isAllDigits(const std::string& s) {
    if (s.empty()) return false;
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

long PmergeMe::toLong(const std::string& s, bool& ok) {
    ok = false;
    if (!isAllDigits(s)) return 0;
    // convertir sin overflow a long
    std::istringstream iss(s);
    long v = 0;
    iss >> v;
    if (!iss.fail() && iss.eof()) ok = true;
    return v;
}

bool PmergeMe::parseArgs(int argc, char** argv, std::vector<int>& outVec) const {
    outVec.clear();
    for (int i = 1; i < argc; ++i) {
        std::string tok(argv[i]);
        bool ok = false;
        long v = toLong(tok, ok);
        if (!ok || v <= 0 || v > INT_MAX) {
            return false; // Error
        }
        outVec.push_back(static_cast<int>(v));
    }
    return !outVec.empty();
}

void PmergeMe::sortVector(std::vector<int>& v) const {
    fjSortVector(v);
}

void PmergeMe::sortDeque(std::deque<int>& d) const {
    fjSortDeque(d);
}

// ------------------ Jacobsthal helpers ------------------

// Construye el orden de inserción (índices 0..n-1) siguiendo bloques definidos por
// la sucesión de Jacobsthal. Inserta en el orden: J(k)-1 ... J(k-1) (descendente),
// acumulando hasta cubrir n elementos.
void PmergeMe::buildJacobsthalOrder(size_t n, std::vector<size_t>& order) {
    order.clear();
    if (n == 0) return;

    // Generar Jacobsthal J: 0,1,1,3,5,11,21,...
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);
    while (true) {
        size_t sz = J.size();
        size_t next = J[sz - 1] + 2 * J[sz - 2];
        if (next > n) break;
        J.push_back(next);
    }
    // Siempre necesitamos al menos J1=1; si n==1, J = {0,1}
    // Procesar bloques k=2..K, insertando índices (J[k]-1 ... J[k-1]), descendente
    size_t prev = 1;
    for (size_t k = 2; k < J.size(); ++k) {
        size_t cur = J[k];
        size_t start = cur - 1;
        size_t stop = prev; // exclusivo inferior
        for (size_t idx = start + 1; idx > stop; --idx) {
            order.push_back(idx - 1);
        }
        prev = cur;
    }
    // Resto hasta n
    if (prev < n) {
        for (size_t idx = n; idx > prev; --idx) {
            order.push_back(idx - 1);
        }
    }
}

// ------------------ Vector implementation ------------------

static void makePairsVector(const std::vector<int>& in,
                            std::vector< std::pair<int,int> >& pairs,
                            bool& hasStraggler,
                            int& straggler) {
    pairs.clear();
    hasStraggler = false;
    straggler = 0;
    size_t i = 0;
    for (; i + 1 < in.size(); i += 2) {
        int a = in[i];
        int b = in[i + 1];
        if (a > b) { int t = a; a = b; b = t; }
        pairs.push_back(std::make_pair(a, b));
    }
    if (i < in.size()) {
        hasStraggler = true;
        straggler = in[i];
    }
}

// Búsqueda binaria en [0, boundIndex) para insertar 'value'
void PmergeMe::binaryInsertVector(std::vector<int>& chain, size_t boundIndex, int value) {
    size_t lo = 0;
    size_t hi = boundIndex; // exclusivo
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (value < chain[mid]) hi = mid;
        else lo = mid + 1;
    }
    chain.insert(chain.begin() + static_cast<long>(lo), value);
}

void PmergeMe::fjSortVector(std::vector<int>& v)
{
    if (v.size() <= 1) return;

    // 1) Emparejar (a=min, b=max) + detectar straggler
    std::vector< std::pair<int,int> > pairs;
    bool hasStraggler = false; int straggler = 0;
    makePairsVector(v, pairs, hasStraggler, straggler);

    // 2) Ordenar recursivamente la cadena principal de máximos (b)
    std::vector<int> maxes;
    maxes.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i) maxes.push_back(pairs[i].second);
    fjSortVector(maxes); // recursión sobre vector de máximos

    // 3) Construir la cadena principal con los 'b' ya ordenados
    std::vector<int> chain = maxes;

    // 4) Preparar lista de mínimos 'a' en el orden de los 'pairs' original
    std::vector<int> mins;
    mins.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i) mins.push_back(pairs[i].first);

    // 5) Insertar los 'a' en order Jacobsthal; cada 'a' se inserta en [0, pos(b)]
    //    pos(b) se encuentra en la cadena actual (puede desplazarse por inserciones previas).
    std::vector<size_t> order;
    buildJacobsthalOrder(mins.size(), order);

    for (size_t oi = 0; oi < order.size(); ++oi) {
        size_t idx = order[oi];           // índice del par a insertar
        int a = mins[idx];
        int b = pairs[idx].second;

        // encontrar posición ACTUAL de b en chain (lineal; suficiente para 3000)
        size_t posB = 0;
        for (; posB < chain.size(); ++posB) {
            if (chain[posB] == b) break;
        }
        if (posB == chain.size()) {
            // fallback: si no se encontrara (duplicados peculiares), insertar en todo el rango
            posB = chain.size();
        }
        binaryInsertVector(chain, posB, a);
    }

    // 6) Insertar el straggler si lo hay (rango completo)
    if (hasStraggler) {
        binaryInsertVector(chain, chain.size(), straggler);
    }

    v.swap(chain);
}

// ------------------ Deque implementation ------------------

static void makePairsDeque(const std::deque<int>& in,
                           std::deque< std::pair<int,int> >& pairs,
                           bool& hasStraggler,
                           int& straggler) {
    pairs.clear();
    hasStraggler = false;
    straggler = 0;
    size_t i = 0;
    for (; i + 1 < in.size(); i += 2) {
        int a = in[i];
        int b = in[i + 1];
        if (a > b) { int t = a; a = b; b = t; }
        pairs.push_back(std::make_pair(a, b));
    }
    if (i < in.size()) {
        hasStraggler = true;
        straggler = in[i];
    }
}

void PmergeMe::binaryInsertDeque(std::deque<int>& chain, size_t boundIndex, int value) {
    size_t lo = 0;
    size_t hi = boundIndex; // exclusivo
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (value < chain[mid]) hi = mid;
        else lo = mid + 1;
    }
    chain.insert(chain.begin() + static_cast<long>(lo), value);
}

void PmergeMe::fjSortDeque(std::deque<int>& d) {
    if (d.size() <= 1) return;

    // 1) Pares
    std::deque< std::pair<int,int> > pairs;
    bool hasStraggler = false; int straggler = 0;
    makePairsDeque(d, pairs, hasStraggler, straggler);

    // 2) Ordenar recursivamente máximos
    std::deque<int> maxes;
    for (size_t i = 0; i < pairs.size(); ++i) maxes.push_back(pairs[i].second);
    fjSortDeque(maxes);

    // 3) Cadena principal
    std::deque<int> chain = maxes;

    // 4) Mínimos
    std::deque<int> mins;
    for (size_t i = 0; i < pairs.size(); ++i) mins.push_back(pairs[i].first);

    // 5) Orden Jacobsthal e inserciones acotadas por la posición de b
    std::vector<size_t> order;
    buildJacobsthalOrder(mins.size(), order);

    for (size_t oi = 0; oi < order.size(); ++oi) {
        size_t idx = order[oi];
        int a = mins[idx];
        int b = pairs[idx].second;

        size_t posB = 0;
        for (; posB < chain.size(); ++posB) {
            if (chain[posB] == b) break;
        }
        if (posB == chain.size()) {
            posB = chain.size();
        }
        binaryInsertDeque(chain, posB, a);
    }

    // 6) Straggler
    if (hasStraggler) {
        binaryInsertDeque(chain, chain.size(), straggler);
    }

    d.swap(chain);
}
