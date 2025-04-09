#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("DefaultRobotomy", 72, 45)
{
	this->_target = "Uranus";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm("DefaultRobotomy", 72, 45)
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

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("DefaultRobotomy", 72, 45)
{
	this->_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw UnsignedFormException();

	int randomNumber = rand();
	std::cout << "* BZZZZZZZZZZZZT * (some drilling noises...)" << std::endl;
	if (randomNumber % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "..." << std::endl;
}