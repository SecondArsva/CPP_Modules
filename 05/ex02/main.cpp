#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat carrera("José Miguel Carrera", 1);
        Bureaucrat español("Gobernador Español", 150);
        Bureaucrat mapuche("Toqui", 42);
		//Bureaucrat anacronismo("Augusto Pinochet", 999); // Caso de excepcion en este alcance/scope.

        Form independencia("Acta de Independencia de Chile", 1, 1);
        Form permisoReal("Permiso Real de España", 150, 150);
        Form pachamama("Qulqi Uru", 42, 42);
		//Form anacronismo("Cerveza Cristal", 999, 999); // Caso de excepcion en este alcance/scope.
		//Form anacronismo("Pablo Neruda", 20, -1); // Caso de excepcion en este alcance/scope.

        std::cout << carrera << std::endl;
        std::cout << español << std::endl;
        std::cout << mapuche << std::endl;
        std::cout << independencia << std::endl;
        std::cout << permisoReal << std::endl;
        std::cout << pachamama << std::endl;

        carrera.signForm(independencia);
        español.signForm(permisoReal);
        español.signForm(pachamama); // El español cree en Dios, no en la tierra

        std::cout << independencia << std::endl;
        std::cout << permisoReal << std::endl;
        std::cout << pachamama << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
