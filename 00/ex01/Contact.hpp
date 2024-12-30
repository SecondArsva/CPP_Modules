#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "header.hpp"

class Contact
{
	private:

		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	
	public:

		// Constructor por defecto para evitar problemas. Sobrecarga de constructores.
		Contact();
		// constructor con parámetros
		Contact(const std::string firstName, const std::string lastName, const std::string nickname, const std::string phoneNumber, const std::string darkestSecret);
		// destructor
		~Contact();

		//métodos para obtener datos
		std::string getFirstName(void)const;
		std::string getLastName(void)const;
		std::string getNickname(void)const;
		std::string getPhoneNumber(void)const;
		std::string getDarkestSecret(void)const;
};

#endif
