#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>  // Para srand(), rand()
#include <ctime>    // Para time()

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	std::srand(std::time(NULL)); // Inicializa la semilla para rand() una sola vez

	try
	{
		Bureaucrat god("God", 1);
		Intern doomer;
		AForm *shru = doomer.makeForm("shrubbery creation", "yo mama");
		AForm *robo = doomer.makeForm("robotomy request", "yo mama");
		AForm *pres = doomer.makeForm("presidential pardon", "yo mama");
		AForm *unkn = doomer.makeForm("phone call", "yo mama"); // <- Esto va a ser NULL

		// Firmar y ejecutar solo si los formularios existen
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

		// Limpieza
		delete shru;
		delete robo;
		delete pres;
		delete unkn; // Es seguro hacer delete nullptr
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	   
    return (0);
}
