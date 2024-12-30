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
			instance.addContact();
		else if (!input.compare("SEARCH"))
			instance.searchContact();
		else if (!input.compare("EXIT"))
			return (std::cout << "See you!" << std::endl, 0);
		else
			std::cout << "Unknown command!" << std::endl << std::endl;
	}
}