#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const &src){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs){ return (*this); }

void ScalarConverter::convert(std::string const &literal)
{
	char c;
	int i;
	float f;
	double d;
}