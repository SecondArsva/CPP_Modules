#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src)
	{
		(void)src;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

const char * ScalarConverter::NonDisplayable::what() const throw()
{
	return ("Non displayable");
}

const char * ScalarConverter::Imposible::what() const throw()
{
	return ("impossible");
}

void ScalarConverter::convert(const std::string &literal)
{

}

char ScalarConverter::convertToChar(const std::string &literal)
{

}

int ScalarConverter::convertToInt(const std::string &literal)
{

}

float ScalarConverter::convertToFloat(const std::string &literal)
{

}

double ScalarConverter::convertToDouble(const std::string &literal)
{

}