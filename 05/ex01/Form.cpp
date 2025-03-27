#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _execGrade(150)
{
	this->_signed = 0;
}

Form::Form(Form const &src)
{
	*this = src;
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		
	}
	return (*this);
}

Form::~Form()
{

}