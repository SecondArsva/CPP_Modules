#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		//return (0);
	}
	{
		Span sp = Span(2);
		sp.addNumber(42);
		try
		{
			std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
				try
		{
			std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		sp.addNumber(-42);
				try
		{
			std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
				try
		{
			std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));

		std::vector<int> bigChungus;
		for (int i = 0; i < 10000; i++)
		{
			bigChungus.push_back(std::rand());
			//std::cout << "New value: " << bigChungus[i] << std::endl;
		}
		Span sp = Span(10000);
		try
		{
			std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		sp.addRange(bigChungus.begin(), bigChungus.end());
		try
		{
			std::cout << "sp.shortestSpan(): " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			std::cout << "sp.longestSpan(): " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			sp.addNumber(std::rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		//sp.addNumber(std::rand());
	}
	return (0);
}