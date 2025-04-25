#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern &Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

Intern::~Intern()
{

}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	int const totalForms = 3;
	std::string const formsNames[totalForms] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (size_t i = 0; i < totalForms; i++)
	{
		if (formsNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(formTarget));
				case 1:
					return (new RobotomyRequestForm(formTarget));
				case 2:
					return (new PresidentialPardonForm(formTarget));
			
				default:
					break;
			}
		}
	}
	
	std::cout << "Wait, that form '" << formName << "' doesn't exist!" << std::endl;
	return (NULL);
}