#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>

// Herramientas de tiempo
double PmergeMe::elapsed_us(const timeval &t0, const timeval &t1)
{
    long sec  = t1.tv_sec  - t0.tv_sec;
    long usec = t1.tv_usec - t0.tv_usec;
    return static_cast<double>(sec) * 1e6 + static_cast<double>(usec);
}

// Validación / Parseo
static bool strToLong_(const std::string &s, long &out)
{
    std::istringstream iss(s);
    iss >> out;
    return !iss.fail() && iss.eof();
}

bool PmergeMe::isPositiveInteger(const std::string &s)
{
    if (s.empty())
		return false;
    for (size_t i = 0; i < s.size(); ++i)
	{
        if (s[i] < '0' || s[i] > '9')
			return false;
    }
    long v;
    if (!strToLong_(s, v))
		return false;
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

// Jacobsthal
// Genera el orden de índices (1..n-1) en bloques Jacobsthal:
// Para k = 2.. mientras j(k) < n: inserta j(k), j(k)-1, ..., j(k-1)+1
std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n)
{
    std::vector<size_t> order;
    if (n <= 1)
		return order;
    // j0=0, j1=1
    std::vector<size_t> j;
    j.push_back(0);
    j.push_back(1);
    // generar hasta cubrir n
    while (true)
	{
        size_t m = j.size();
        size_t next = j[m-1] + 2 * j[m-2];
        if (next >= n)
		{
			j.push_back(next);
			break;
		}
        j.push_back(next);
    }
    // construir el orden a partir de bloques (notar que el índice 0 ya se trata aparte)
    for (size_t k = 2; k < j.size(); ++k)
	{
        size_t a = j[k-1];
        size_t b = j[k];
        if (a >= n)
			break;
        if (b > n)
			b = n;
        // insertar desde b-1 bajando hasta a+1 (ambos exclusivos de 0)
        for (size_t idx = b; idx-- > a + 1; )
		{
            order.push_back(idx);
        }
    }
    return order;
}

// Pares y extracción
template <typename Seq>
void PmergeMe::makePairs(const Seq &in, std::vector< Pair<typename Seq::value_type> > &pairs, bool &hasOdd, typename Seq::value_type &odd) {
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
    if (hasOdd) odd = in.back();
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

template <typename T>
std::vector<T> PmergeMe::extractSmallsReordered(const std::vector< Pair<T> > &pairs, const std::vector<T> &sortedBigs)
{
    // Para cada big ordenado, localizar su "small" asociado y extraerlo en ese orden.
    std::vector<T> out;
    out.reserve(pairs.size());
    for (size_t i = 0; i < sortedBigs.size(); ++i)
	{
        T bg = sortedBigs[i];
        // búsqueda lineal (pares son pocos comparado con N); aceptable en C++98
        for (size_t k = 0; k < pairs.size(); ++k)
		{
            if (pairs[k].big == bg)
			{
				out.push_back(pairs[k].small);
				break;
			}
        }
    }
    return out;
}

// Inserción binaria manual en rango [left, right)
template <typename Seq, typename T>
typename Seq::iterator PmergeMe::binInsert(Seq &mainChain, const T &value, size_t left, size_t rightExclusive)
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
    // insertar en posición lo
    typename Seq::iterator it = mainChain.begin() + static_cast<typename Seq::difference_type>(lo);
    return mainChain.insert(it, value);
}

// Núcleo Ford–Johnson genérico (oculto)
template <typename Seq>
void PmergeMe::fj_impl(Seq &a)
{
    if (a.size() <= 1)
		return;

    // 1) Emparejar (big, small) y posible impar
    typedef typename Seq::value_type T;
    std::vector< Pair<T> > pairs;
    bool hasOdd = false;
    T odd = T();
    makePairs(a, pairs, hasOdd, odd);

    // 2) Ordenar recursivamente por los BIG de cada par
    std::vector<T> bigs = extractBigs(pairs);
    // Recursión sobre un contenedor temporal del mismo tipo que a
    Seq bigsSeq(bigs.begin(), bigs.end());
    fj_impl(bigsSeq); // ahora bigsSeq está ordenado

    // 3) Cadena principal: BIGs ordenados
    Seq mainChain = bigsSeq;

    // 4) PEND: SMALLs reordenados según el orden de BIGs
    std::vector<T> smalls = extractSmallsReordered(pairs, std::vector<T>(bigsSeq.begin(), bigsSeq.end()));

    // 5) Insertar el primer SMALL (asociado al primer BIG) en el rango [0, posBIG)
    //    Al ser el primero, su posBIG es 0 -> se inserta al principio.
    if (!smalls.empty())
	{
        binInsert(mainChain, smalls[0], 0, 0); // rango vacío => al principio
    }

    // Para el resto, usamos orden de Jacobsthal sobre índices 1..smalls.size()-1
    std::vector<size_t> order = buildJacobsthalOrder(smalls.size());

    // Para cada índice i del orden, insertamos smalls[i] en [0, posBIG(i))
    // posBIG(i) = posición de su BIG en mainChain en ese momento.
    for (size_t idx = 0; idx < order.size(); ++idx)
	{
        size_t i = order[idx];
        if (i >= smalls.size())
			continue;

        T bigVal = bigsSeq[i]; // BIG correspondiente
        // localizar posBIG actual (búsqueda binaria manual sobre mainChain)
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
        size_t posBIG = lo; // donde está BIG
        binInsert(mainChain, smalls[i], 0, posBIG);
    }

    // 6) Si había impar, insertarlo en toda la cadena
    if (hasOdd)
	{
        binInsert(mainChain, odd, 0, mainChain.size());
    }

    // 7) Volcar resultado
    a.assign(mainChain.begin(), mainChain.end());
}

// Wrappers específicos por contenedor
void PmergeMe::fordJohnson(std::vector<int> &a) { fj_impl(a); }
void PmergeMe::fordJohnson(std::deque<int> &a)  { fj_impl(a); }

// Orquestación / run
void PmergeMe::run(int argc, char** argv)
{
    // Parseo
    std::vector<int> v = parseAll< std::vector<int> >(argc, argv);
    std::deque<int>  d(v.begin(), v.end());

    // Imprimir BEFORE
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); ++i)
	{
        if (i)
			std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << std::endl;

    // Vector
    timeval t0v, t1v;
    gettimeofday(&t0v, 0);
    fordJohnson(v);
    gettimeofday(&t1v, 0);

    // Deque
    timeval t0d, t1d;
    gettimeofday(&t0d, 0);
    fordJohnson(d);
    gettimeofday(&t1d, 0);

    // Comprobación (opcional): el resultado debe ser igual en ambos
    // y estar no decreciente
    // (No lanzamos excepción aquí; el subject deja libre el manejo de duplicados.)

    // Imprimir AFTER (desde vector)
    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); ++i)
	{
        if (i)
			std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << std::endl;

    // Tiempos
    double usVec = elapsed_us(t0v, t1v);
    double usDeq = elapsed_us(t0d, t1d);
    std::cout << "Time to process a range of " << v.size()
              << " elements with std::vector : " << usVec << " us" << std::endl;
    std::cout << "Time to process a range of " << d.size()
              << " elements with std::deque  : " << usDeq << " us" << std::endl;
}
