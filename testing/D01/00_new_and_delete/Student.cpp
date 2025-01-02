#include "Student.hpp"

Student::Student(std::string name) : studentName(name)
{
	std::cout << "Constructor called" << std::endl;

	std::cout << "Hi, I'm " << this->studentName << std::endl;

	return ;
}

Student::~Student()
{
	std::cout << "Destructor called" << std::endl;
	
	std::cout << "Bye, I'm " << this->studentName << std::endl;
	
	return ;
}