#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>  // Para srand(), rand().
#include <ctime>    // Para time().

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL)); // Inicializa la semilla para la función rand() una sola vez.

	try
	{
		Bureaucrat god("God", 1);
		Intern doomer;
		std::string target = "yo_mama";
		AForm *shru = doomer.makeForm("shrubbery creation", target);
		AForm *robo = doomer.makeForm("robotomy request", target);
		AForm *pres = doomer.makeForm("presidential pardon", target);
		AForm *unkn = doomer.makeForm("phone call", target); // <- Esto va a ser NULL.

		// Firmar y ejecutar solo si los formularios existen.
		if (shru)
		{
			god.signForm(*shru);
			god.executeForm(*shru);
		}

		if (robo)
		{
			god.signForm(*robo);
			god.executeForm(*robo);
		}

		if (pres)
		{
			god.signForm(*pres);
			god.executeForm(*pres);
		}

		if (unkn)
		{
			god.signForm(*unkn);
			god.executeForm(*unkn);
		}

		// Limpieza.
		delete shru;
		delete robo;
		delete pres;
		delete unkn; // Es seguro hacer un delete incluso del NULL pointer.
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

    return (0);
}
