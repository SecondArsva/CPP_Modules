#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150)
{
	this->_signed = 0;
}

AForm::AForm(AForm const &src) : _name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	*this = src;
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return (*this);
}

AForm::~AForm()
{

}

AForm::AForm(std::string const name, int const signGrade, int const execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	this->_signed = false;
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw GradeTooHighException();
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw GradeTooLowException();
}

std::string AForm::getName()const
{
	return (this->_name);
}

bool AForm::getSigned()const
{
	return (this->_signed);
}

int AForm::getSignGrade()const
{
	return (this->_signGrade);
}

int AForm::getExecGrade()const
{
	return (this->_execGrade);
}

void AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, AForm const &rhs)
{
	os << "AForm: " << rhs.getName() << std::endl
	<< "\t Signed: " << rhs.getSigned() << std::endl
	<< "\t Min grade to sign: " << rhs.getSignGrade() << std::endl
	<< "\t Min grade to exec: " << rhs.getExecGrade() << std::endl;
	return(os);
}