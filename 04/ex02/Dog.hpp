#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{	
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog const &src);
		Dog &operator=(Dog const &rhs);
		~Dog();

		virtual void makeSound()const;
		
		Brain *getBrain(void)const;
		std::string getIdeas(int const index)const;
		void setIdeas(int const index, std::string const idea);
};

#endif
