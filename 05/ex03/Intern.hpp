#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		Intern &operator=(Intern const &rhs);
		~Intern();

		AForm *makeForm(std::string formName, std::string formTarget);
};

#endif