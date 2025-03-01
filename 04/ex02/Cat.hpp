#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Cat const &src);
		Cat &operator=(Cat const &rhs);
		~Cat();

		virtual void makeSound()const;
		
		Brain *getBrain(void)const;
		std::string getIdeas(int const index)const;
		void setIdeas(int const index, std::string const idea);
};

#endif
