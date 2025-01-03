#include <iostream>

void byPtr(std::string *str)
{
	*str += " and ponies";
}

void byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;	
}

void byRef(std::string &str)
{
	str += " and dragons";
}

void byConstRef (std::string const &str)
{
	std::cout << str << std::endl;
}

int main(void)
{
	std::string str = "I like butterflies";
	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "I like others";
	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);
	return (0);
}