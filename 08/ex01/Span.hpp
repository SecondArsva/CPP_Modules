#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:
		Span(unsigned int N);
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span();

		void addNumber(int num);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		// EXCEPTIONS

		// Span is full
		class NoMoreRoomInHellException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		// Throwed when shortestSpan() or longestSpan() are called with less than 2 elements
		class NotEnoughElementsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif