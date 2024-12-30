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
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 9; i++)
	{
		std::cout << "|" << "         " << (int)i + 1 << "|";
		// TODO: Fist Name, Last name y Nickname
		std::cout << this->formatInfo(this->_contacts[i].getFirstName()) << "|";
		std::cout << this->formatInfo(this->_contacts[i].getLastName()) << "|";
		std::cout << this->formatInfo(this->_contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
	std::string index = "";
	std::cout << "Insert an index number to display the contact info: ";
	std::cin >> index;
}

std::string PhoneBook::formatInfo(std::string str)
{
	if (str.length() == 10)
		return (str);
	// TODO if < 10 go espaces | else if > 10 go dot .
	return ("hola");
}