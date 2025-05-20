#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		
		static char convertChar(const std::string &literal);
		static int convertInt(const std::string &literal);
		static float convertFloat(const std::string &literal);
		static double convertDouble(const std::string &literal);
		
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
