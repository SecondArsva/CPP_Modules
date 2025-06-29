#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat def;
		std::cout << def << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat llados("Llados", 1);
		std::cout << llados << std::endl;
		for (size_t i = 0; i < 149; i++)
			llados.decrementGrade();
		std::cout << llados << std::endl;
		llados.decrementGrade();
		// Al lanzarse la excepción al llegar a 151
		// no se ejecuta lo siguiente, saltando al "catch".
		std::cout << llados << std::endl;
	}
	catch(const std::exception &e)
	{
		// Como se lanzó una excepción, el "catch" la captura
		// y se ejecuta el código dentro a su alcance (scope).
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat panza("Panza", 42);
		Bureaucrat npc("NPC", 142);
		Bureaucrat unk(npc);
		Bureaucrat nown = panza;
		npc = panza;
		npc.incrementGrade();
		std::cout << npc << std::endl;
		std::cout << unk << std::endl;
		std::cout << nown << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat lingxiaoHeLin("Lingxiao He Lin", 1);
	std::cout << lingxiaoHeLin << std::endl;
	try
	{
		lingxiaoHeLin.incrementGrade();
		std::cout << lingxiaoHeLin << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "inside the 'catch'" << std::endl;
		std::cout << lingxiaoHeLin << std::endl;
	}
	
	return (0);
}