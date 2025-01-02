#include "StudentArray.hpp"

int StudentArray::total = 0;

StudentArray::StudentArray() : studentName("default")
{
	this->id = StudentArray::total;
	std::cout << "Hi, I'm " << this->studentName << this->id << std::endl;
	StudentArray::total += 1;
	return ;
}

StudentArray::~StudentArray()
{
	std::cout << "Bye, I'm " << this->studentName << this->id << std::endl;
	return ;
}