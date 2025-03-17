#include <stdexcept>

void test1()
{
	try
	{
		// Do some stuff here
		if (/* there's an error */)
		{
			throw std::exception();
		}
		else
		{
			// do some stuff here
		}
	}
	catch (std::exception e)
	{
		// Handle the error here
	}
}

void test2()
{
	// Do some stuff here
	if (/* there's an error */)
	{
		throw std::exception();
	}
	else
	{
		// Do some more stuff
	}
}

void test3()
{
	try
	{
		test2();
	}
	catch (std::exception &e)
	{
		// Handle error
	}
}

void test4()
{
	class PEBKACException : public std::exception
	{
		public:
			/* El throw al final de la función miembro
			significa que puede lanzar (throw) algo.
			Si "throw" no tiene ningún parámetro quiere
			decir que no se lanzarán excepciones.
			Si recibiese algún parámetro, indica que la
			función solo lanzará excepciones de esos tipos.
			
			void funcion() throw(); Equivalente a noexcept(true) de C++11
			void miFuncion() throw(std::runtime_error, int);*/

			virtual const char* what() const throw()
			{
				return ("Problem exists between keyboard and chair");
			}
	};

	try
	{
		test3();
	}
	catch (PEBKACException &e)
	{
		// Handle the fact that the user is an idiot
	}
	catch (std::exception &e)
	{
		// Handle other exception that are like std::exception
	}
}
