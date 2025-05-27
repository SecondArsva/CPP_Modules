#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(std::string literal);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		
		static char convertToChar(const std::string &literal);
		static int convertToInt(const std::string &literal);
		static float convertToFloat(const std::string &literal);
		static double convertToDouble(const std::string &literal);
		
		class NonDisplayable : public std::exception
		{
			public:
				const char * what() const throw();
		};
		
		class Imposible : public std::exception
		{
			public:
				const char * what() const throw();
		};
		
	public:
		
		~ScalarConverter();
		static void convert(const std::string &literal);
		
};

#endif
