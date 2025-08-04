#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const &src)
{
	*this = src;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw Span::NoMoreRoomInHellException();
	_numbers.push_back(num);
	
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughElementsException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        unsigned int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();
	
	int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw NoMoreRoomInHellException();
	_numbers.insert(_numbers.end(), begin, end);
}

const char *Span::NoMoreRoomInHellException::what() const throw()
{
	return ("Exception: Span is already full");
}

const char* Span::NotEnoughElementsException::what()const throw()
{
	return ("Exception: Not enough elements to calculate a span");
}