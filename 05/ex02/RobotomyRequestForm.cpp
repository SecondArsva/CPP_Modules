#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("DefaultRobotomy", 72, 52)
{
	this->_target = "Uranus";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm("DefaultRobotomy", 72, 52)
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("DefaultRobotomy", 72, 52)
{
	this->_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() < this->getExecGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw UnsignedFormException();
	// do the thing
}