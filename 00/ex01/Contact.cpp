#include "Contact.hpp"

// Constructor por defecto, inicializa el objeto con cadenas vacías.
Contact::Contact(): _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret(""){}
// Constructor con parámetros, inicializa valores usando una lista de inicialización.
Contact::Contact(const std::string firstName, const std::string lastName, const std::string nickname, const std::string phoneNumber, const std::string darkestSecret) : _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret){}

Contact::~Contact(){}

std::string	Contact::getFirstName()const{return (this->_firstName);}
std::string	Contact::getLastName()const{return (this->_lastName);}
std::string	Contact::getNickname()const{return (this->_nickname);}
std::string	Contact::getPhoneNumber()const{return (this->_phoneNumber);}
std::string	Contact::getDarkestSecret()const{return (this->_darkestSecret);}
