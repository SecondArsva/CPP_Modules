#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &src);
		Dog &operator=(Dog const &rhs);
		~Dog();

		virtual void makeSound()const;
};

#endif
