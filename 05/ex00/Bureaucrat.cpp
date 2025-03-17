#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName()const
{
	return (this->_name);
}

int Bureaucrat::getGrade()const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	this->_grade--;
}


void Bureaucrat::decrementGrade()
{
	this->_grade++;
}

void Bureaucrat::operator<<(Bureaucrat const &rhs)
{
	std::cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
}