#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal &operator=(WrongAnimal const &rhs);
		~WrongAnimal(); /* Como el destructor de la clase base no es virtual,
		no se liberará correctamente la clase derivada al usar "delete" */

		void makeSound()const; /* No es virtual, por lo que causa problemas.
		No hay polimorfismo */
		std::string getType(void)const;
		void		setType(std::string type);
};

#endif