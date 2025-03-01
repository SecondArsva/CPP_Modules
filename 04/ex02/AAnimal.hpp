#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

/*	En C++98, si una clase tiene métodos virtuales,
	su destructor también debe ser virtual.

	Esto es crucial para garantizar la correcta destrucción de los objetos
	cuando se eliminan a través de un puntero a la clase base.
*/

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(AAnimal const &src);
		AAnimal &operator=(AAnimal const &rhs);
		virtual ~AAnimal();

		virtual void makeSound()const = 0; /* Miembro virtual puro.
		Hace que la clase sea abstracta. */
		std::string getType(void)const;
		void		setType(std::string type);
};

#endif