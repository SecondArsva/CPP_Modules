#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "header.hpp"
# include "Contact.hpp"

class PhoneBook
{
	private:
	
		Contact _contacts[8];
		int		_oldestIndex;
	
	public:

		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();
		void	formatInfo(std::string str);
};

#endif
