#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		WrongCat &operator=(WrongCat const &rhs);
		~WrongCat();

		void makeSound()const; /* No es virtual. No hay polimorfismo.
		Intenta sobrescribir, pero no funciona correctamente.
		Mostrándose el mensaje de la clase base WrongAnimal.
		*/ 
};

#endif