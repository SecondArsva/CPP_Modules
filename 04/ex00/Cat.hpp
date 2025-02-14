#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string _type;
	public:
		Cat();
		Cat(Cat const &src);
		Cat &operator=(Cat const &rhs);
		~Cat();

		virtual void makeSound()const;
};

#endif