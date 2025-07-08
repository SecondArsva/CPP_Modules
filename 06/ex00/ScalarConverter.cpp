#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const &src){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs){ return (*this); }

static bool isChar(std::string const &str)
{
	return (str.length() == 1 && !isdigit(str[0]));
}

static bool isInt(std::string const &str)
{
	char *end;
	std::strtol(str.c_str(), &end, 10);
	return (end == '\0');
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
	if (str == "nanf" || str == "+inff" || str == "-inff")
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

	if (isChar(literal))
	{
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (isInt(literal))
	{

	}
	else if (isFloat(literal))
	{

	}
	else if (isDouble(literal))
	{

	}
	else
	{

	}
}