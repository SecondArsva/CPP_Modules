#include "header.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook instance;
	std::string input;

	while (true)
	{
		std::cout << "Commands accepted: "
			<< "'ADD', 'SEARCH' and 'EXIT'" << std::endl;
		std::cout << "Enter a command: ";
		std::cin >> input;

		if (!input.compare("ADD"))
		{
			instance.addContact();
			//std::cout << std::setw(10);
			//std::cout << "hola";
		}
		else if (!input.compare("SEARCH"))
			instance.searchContact();
		else if (!input.compare("EXIT"))
			return (0);
		else
			std::cout << "Unknown command: '" << input << "'" << std::endl;
	}
}