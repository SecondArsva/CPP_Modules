#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>

// ------------------ Canonical ------------------
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}

// ------------------ Tiempo ---------------------
double PmergeMe::elapsed_us(const timeval &t0, const timeval &t1)
{
    long sec  = t1.tv_sec  - t0.tv_sec;
    long usec = t1.tv_usec - t0.tv_usec;
    return static_cast<double>(sec) * 1e6 + static_cast<double>(usec);
}

// ---------------- Validación / Parseo ----------
static bool strToLong_(const std::string &s, long &out)
{
    std::istringstream iss(s);
    iss >> out;
    return !iss.fail() && iss.eof();
}

bool PmergeMe::isPositiveInteger(const std::string &s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    long v;
    if (!strToLong_(s, v)) return false;
    return v > 0 && v <= INT_MAX;
}

int PmergeMe::parseOne(const std::string &s)
{
    if (!isPositiveInteger(s))
		throw std::runtime_error("Error");
    long v;
    if (!strToLong_(s, v))
		throw std::runtime_error("Error");
    if (v <= 0 || v > INT_MAX)
		throw std::runtime_error("Error");
    return static_cast<int>(v);
}

template <typename Seq>
Seq PmergeMe::parseAll(int argc, char** argv)
{
    Seq out;
    for (int i = 1; i < argc; ++i)
	{
        std::string tok(argv[i]);
        if (tok.empty())
			throw std::runtime_error("Error");
        out.push_back(parseOne(tok));
    }
    if (out.empty())
		throw std::runtime_error("Error");
    return out;
}

// ---------------- Jacobsthal -------------------
std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n)
{
    // n = número de SMALLs (size de 'smalls')
    // Queremos índices en [1..n-1] en bloques Jacobsthal: 1 ; 3,2 ; 7,6,5,4 ; ...
    std::vector<size_t> order;
    if (n <= 1) return order;

    // Secuencia de Jacobsthal: J0=0, J1=1, Jk = J(k-1) + 2*J(k-2)
    std::vector<size_t> J;
    J.push_back(0);
    J.push_back(1);

    // Asegura al menos J2 y cubre hasta >= (n-1)
    while (J.size() < 3 || J.back() < n - 1) {
        size_t m = J.size();
        J.push_back(J[m - 1] + 2 * J[m - 2]);
    }

    size_t limit = n - 1; // índices válidos: 1..limit
    for (size_t k = 2; k < J.size(); ++k) {
        size_t start = J[k];
        if (start > limit) start = limit;

        // Siempre empuja J(k) si está dentro de [1..limit]
        if (start >= 1) order.push_back(start);

        // Luego el bloque descendente hasta J(k-1)+1 (excluyendo start que ya añadimos)
        size_t stop = J[k - 1] + 1;
        if (start > stop) {
            // usar índice con signo para evitar underflow
            for (long idx = static_cast<long>(start) - 1; idx >= static_cast<long>(stop); --idx) {
                order.push_back(static_cast<size_t>(idx));
            }
        }
    }
    return order;
}

// -------------- Pares y extracción -------------
template <typename Seq>
void PmergeMe::makePairs(const Seq &in,
                         std::vector< Pair<typename Seq::value_type> > &pairs,
                         bool &hasOdd,
                         typename Seq::value_type &odd)
{
    pairs.clear();
    hasOdd = (in.size() % 2 != 0);
    size_t limit = in.size() - (hasOdd ? 1 : 0);
    for (size_t i = 0; i < limit; i += 2)
	{
        typename Seq::value_type a = in[i];
        typename Seq::value_type b = in[i+1];
        Pair<typename Seq::value_type> p;
        if (a >= b)
		{
			p.big = a;
			p.small = b;
		}
        else
		{
			p.big = b;
			p.small = a;
		}
        pairs.push_back(p);
    }
    if (hasOdd)
		odd = in.back();
}

template <typename T>
std::vector<T> PmergeMe::extractBigs(const std::vector< Pair<T> > &pairs)
{
    std::vector<T> out;
    out.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i)
        out.push_back(pairs[i].big);
    return out;
}

// FIX: soportar BIGs duplicados marcando pares usados
template <typename T>
std::vector<T> PmergeMe::extractSmallsReordered(const std::vector< Pair<T> > &pairs,
                                                const std::vector<T> &sortedBigs)
{
    std::vector<T> out;
    out.reserve(pairs.size());
    std::vector<bool> used(pairs.size(), false);

    for (size_t i = 0; i < sortedBigs.size(); ++i)
	{
        T bg = sortedBigs[i];
        bool found = false;
        for (size_t k = 0; k < pairs.size(); ++k)
		{
            if (!used[k] && pairs[k].big == bg)
			{
                out.push_back(pairs[k].small);
                used[k] = true;
                found = true;
                break;
            }
        }
        (void)found; // si quieres, puedes comprobar consistencia aquí
    }
    return out;
}

// -------- Inserción binaria en [left, right) ----
template <typename Seq, typename T>
typename Seq::iterator PmergeMe::binInsert(Seq &mainChain, const T &value,
                                           size_t left, size_t rightExclusive)
{
    size_t lo = left;
    size_t hi = rightExclusive;
    while (lo < hi)
	{
        size_t mid = lo + (hi - lo) / 2;
        if (value < mainChain[mid])
			hi = mid;
        else
			lo = mid + 1;
    }
    typename Seq::iterator it = mainChain.begin()
        + static_cast<typename Seq::difference_type>(lo);
    return mainChain.insert(it, value);
}

// --------- Núcleo Ford–Johnson genérico --------
template <typename Seq>
void PmergeMe::fj_impl(Seq &a)
{
    if (a.size() <= 1)
		return;

    typedef typename Seq::value_type T;
    std::vector< Pair<T> > pairs;
    bool hasOdd = false;
    T odd = T();
    makePairs(a, pairs, hasOdd, odd);

    std::vector<T> bigs = extractBigs(pairs);
    Seq bigsSeq(bigs.begin(), bigs.end());
    fj_impl(bigsSeq); // ordenar BIGs

    Seq mainChain = bigsSeq;

    std::vector<T> smalls = extractSmallsReordered(
        pairs, std::vector<T>(bigsSeq.begin(), bigsSeq.end())
    );

    if (!smalls.empty())
	{
        binInsert(mainChain, smalls[0], 0, 0); // insertar al principio
    }

    std::vector<size_t> order = buildJacobsthalOrder(smalls.size());

    for (size_t idx = 0; idx < order.size(); ++idx)
	{
        size_t i = order[idx];
        if (i >= smalls.size())
			continue;

        T bigVal = bigsSeq[i];
        // localizar posición actual de bigVal en mainChain (búsqueda binaria)
        size_t lo = 0, hi = mainChain.size();
        while (lo < hi)
		{
            size_t mid = lo + (hi - lo) / 2;
            if (bigVal < mainChain[mid])
				hi = mid;
            else if (mainChain[mid] < bigVal)
				lo = mid + 1;
            else
			{
				lo = hi = mid;
				break;
			}
        }
        size_t posBIG = lo;
        binInsert(mainChain, smalls[i], 0, posBIG);
    }

    if (hasOdd)
	{
        binInsert(mainChain, odd, 0, mainChain.size());
    }

    a.assign(mainChain.begin(), mainChain.end());
}

// Wrappers específicos por contenedor
void PmergeMe::fordJohnson(std::vector<int> &a) { fj_impl(a); }
void PmergeMe::fordJohnson(std::deque<int> &a)  { fj_impl(a); }

// ----------------- Orquestación ----------------
void PmergeMe::run(int argc, char** argv)
{
    // Parseo base (argv -> vector)
    std::vector<int> v = parseAll< std::vector<int> >(argc, argv);

    // BEFORE
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); ++i)
	{
        if (i)
			std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << std::endl;

    // Medición INCLUYENDO gestión de datos (como pide el subject):
    // Vector: copia + ordenar
    timeval t0v, t1v;
    gettimeofday(&t0v, 0);
    std::vector<int> vv = v;      // gestión de datos
    fordJohnson(vv);              // ordenación
    gettimeofday(&t1v, 0);

    // Deque: construcción desde v + ordenar
    timeval t0d, t1d;
    gettimeofday(&t0d, 0);
    std::deque<int> dd(v.begin(), v.end()); // gestión de datos
    fordJohnson(dd);                        // ordenación
    gettimeofday(&t1d, 0);

    // AFTER (desde vv)
    std::cout << "After: ";
    for (size_t i = 0; i < vv.size(); ++i)
	{
        if (i)
			std::cout << ' ';
        std::cout << vv[i];
    }
    std::cout << std::endl;

    // Tiempos
    double usVec = elapsed_us(t0v, t1v);
    double usDeq = elapsed_us(t0d, t1d);
    std::cout << "Time to process a range of " << vv.size()
              << " elements with std::vector : " << usVec << " us" << std::endl;
    std::cout << "Time to process a range of " << dd.size()
              << " elements with std::deque  : " << usDeq << " us" << std::endl;
}

// ----------------- Instanciación de plantillas usadas en este TU -----------------
// (Opcional en este caso porque todas se usan dentro de este .cpp, pero explícitas por claridad)
template std::vector<int> PmergeMe::parseAll<std::vector<int> >(int, char**);
