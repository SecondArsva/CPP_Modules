#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_oldestIndex = 0;
}

PhoneBook::~PhoneBook(){}

void PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "Last Name: ";
	std::cin >> lastName;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	std::cout << "Phone Number: ";
	std::cin >> phoneNumber;
	std::cout << "Darkest Secret: ";
	std::cin >> darkestSecret;
	
	Contact toAdd(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->_contacts[_oldestIndex] = toAdd;
	this->_oldestIndex++;
	if (this->_oldestIndex == 8)
		this->_oldestIndex = 0;
}

void PhoneBook::searchContact()
{
	// tabla de contactos
	std::cout << std::endl << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|         " << (i + 1) << "|";
		if (!this->_contacts[i].getFirstName().empty())
		{
			this->formatInfo(this->_contacts[i].getFirstName()); std::cout << "|";
			this->formatInfo(this->_contacts[i].getLastName());  std::cout << "|";
			this->formatInfo(this->_contacts[i].getNickname());  std::cout << "|";
			std::cout << std::endl;
		}
		else
			std::cout << "          |          |          |" << std::endl;
	}
	std::cout << std::endl;
	// búsqueda por índice
	std::string index = "";
	int			indexInt = 0;
	std::cout << "Insert an index number to display the contact info: ";
	std::cin >> index;
	indexInt = atoi(index.c_str());
	// control: Validez del índice
	if (indexInt < 0 && indexInt > 8)
	{
		std::cout << std::endl << index << "'" << index << "'its not a valid index" << std::endl << std::endl;
		return ;
	}
	// control: Existencia de clase
	if (this->_contacts[indexInt - 1].getFirstName().empty())
	{
		std::cout << std::endl << "Empty contact" << std::endl << std::endl;
		return ;
	}
	// impresión de los datos del contacto
	std::cout << std::endl;
	std::cout << "First Name:	" << this->_contacts[indexInt - 1].getFirstName() << std::endl;
	std::cout << "Last Name:	" << this->_contacts[indexInt - 1].getLastName() << std::endl;
	std::cout << "Nickame:	" << this->_contacts[indexInt - 1].getNickname() << std::endl;
	std::cout << "Phone Number:	" << this->_contacts[indexInt - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:	" << this->_contacts[indexInt - 1].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

void PhoneBook::formatInfo(std::string str)
{
	// TODO if < 10 go espaces | else if > 10 go dot .
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << str;
}