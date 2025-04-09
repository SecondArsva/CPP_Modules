#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>  // Para srand(), rand()
#include <ctime>    // Para time()

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	std::srand(std::time(NULL)); // Inicializa la semilla para rand() una sola vez

    try
	{
		Bureaucrat signer("El Firmas", 25);
		Bureaucrat exe("Ejecutor", 5);
		Bureaucrat egg("Exeggutor", 45);

		AForm *shru = new ShrubberyCreationForm("Deku");
		AForm *robo = new RobotomyRequestForm("Master Chief");
		AForm *pres = new PresidentialPardonForm("Bumblebee");

		signer.signForm(*shru);
		signer.signForm(*robo);
		signer.signForm(*pres);

		exe.executeForm(*shru);
		exe.executeForm(*robo);
		exe.executeForm(*pres);

		delete shru;
		delete robo;
		delete pres;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
    
    return (0);
}
