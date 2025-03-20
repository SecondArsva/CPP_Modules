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

Bureaucrat::~Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();

	this->_grade = grade;
}

std::string Bureaucrat::getName()const
{
	return (this->_name);
}

int Bureaucrat::getGrade()const
{
	return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("exception: grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("exception: grade is too low");
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs)
{
	stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (stream);
}