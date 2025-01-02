#include <iostream>

int main(void)
{
	char	buff[512];

	std::cout << "¡Hola mundo!" << std::endl;

	std::cout << "Introduce una palabra: ";
	std::cin >> buff;
	std::cout << "Has introducido: ["<< buff <<"]" << std::endl;

	return (0);
}