#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &src){(void)src;}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return (*this);
}

static bool isChar(std::string const &str)
{
	return (str.length() == 1 && !isdigit(str[0]));
}

static bool isInt(std::string const &str)
{
	char *end;
	std::strtol(str.c_str(), &end, 10);
	return (*end == '\0');
}
static bool isFloat(std::string const &str)
{
	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (true);
	char *end;
	std::strtof(str.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(std::string const &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
		return (true);
	char *end;
	std::strtod(str.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::convert(std::string const &literal)
{
	char c;
	int i;
	float f;
	double d;

    std::cout << std::fixed << std::setprecision(1);

	if (isChar(literal))
	{
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (isInt(literal))
	{
		long l = std::strtol(literal.c_str(), NULL, 10);
		if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            return;
		}
		i = static_cast<int>(l);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	else if (isFloat(literal))
	{
		f = std::strtof(literal.c_str(), NULL);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		c = static_cast<char>(i);
	}
	else if (isDouble(literal))
	{
		d = std::strtod(literal.c_str(), NULL);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(i);
	}
	else
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}

	if (isprint(c))
		std::cout << "char: '" << c << "'\n";
	else if (literal == "nan" || literal == "nanf")
		std::cout << "char: impossible\n";
	else
		std::cout << "char: Non displayable\n";
	
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || d != d)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << "\n";

    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
}
