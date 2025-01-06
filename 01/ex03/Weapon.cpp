#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

/* La convención más común en C++ coloca la palabra clave "const" antes del tipo.
   "const std::string &" y "std::string const &" hacen lo mismo.
   De hecho hay gente que lo coloca después para así ver antes el tipo que
   devuelve y no liarse leyendo de más por el "const".
*/
std::string const &Weapon::getType(void)const
{
	return (this->_type);
}

Weapon::~Weapon(){}