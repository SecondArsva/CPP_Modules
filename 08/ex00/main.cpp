#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include "easyfind.hpp"

template<typename Container>
void print_container(Container const &container, std::string const &name)
{
	std::cout << "Contenido de " << name << ":";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int bad_args(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}

void test_vector(std::vector<int> &v, int to_find)
{
	try
	{
		std::vector<int>::iterator it = easyfind(v, to_find);
		std::cout << "Found: " << *it << " in vector" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test_deque(std::deque<int> &d, int to_find)
{
	try
	{
		std::deque<int>::iterator it = easyfind(d, to_find);
		std::cout << "Found: " << *it << " in deque" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void test_list(std::list<int> &l, int to_find)
{
	try
	{
		std::list<int>::iterator it = easyfind(l, to_find);
		std::cout << "Found" << *it << " in list" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int *fill_array(int size, char **argv)
{
	int *array = new int[size];

	for (int i = 0; i < size; i++)
		array[i] = std::atoi(argv[i + 1]);
	for (int i = 0; i < size; i++)
		std::cout << array[i] << std::endl;
	return(array);
}

int main(int argc, char **argv)
{
	if (argc < 3 || bad_args(argc, argv))
	{
		std::cout <<
		"Intruduce exclusivamente argumentos numéricos junto a la ejecución del programa.\n"
		"Además de 3 argumentos en adelante, programa incluído.\n\n"
		"Los valores que precedan al argumento de la ejecución del programa serán introducidos\n"
		"en los diferentes contenedores para realizar las pruebas con la función plantilla\n"
		"easyfind(), a excepción del último valor, que corresponderá al que se deberá encontrar\n"
		"dentro del contenedor. Contenedores: vetor, deque y list.\n\n"
		"Ejemplo: './easyfind -42 115' <---( to_find )\n";
		return (1);
	}
	
	int to_find = std::atoi(argv[argc - 1]);
	std::cout << "Value to find: " << to_find << std::endl;
	int size = argc - 2;
	int *array = fill_array(size, argv);
	std::vector<int> v(array, array + size); // constructor de rango del contenedor
	print_container(v, "vector");
	std::deque<int> d(array, array + size); // constructor de rango del contenedor
	print_container(d, "deque");
	std::list<int> l(array, array + size); // constructor de rango del contenedor
	print_container(l, "list");
	delete[] array;

	test_vector(v, to_find);
	test_deque(d, to_find);
	test_list(l, to_find);
	return (0);
}
