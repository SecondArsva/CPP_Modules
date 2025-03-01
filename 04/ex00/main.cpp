#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal *meta = new Animal(); // Unknown base type
		const Animal *i = new Cat();
		const Animal *j = new Dog();
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;

		meta->makeSound();
		i->makeSound(); //will output the cat sound!
		j->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	{
		const WrongAnimal *base = new WrongAnimal();
		const WrongAnimal *cat = new WrongCat();

		std::cout << base->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		
		base->makeSound();
		cat->makeSound();

		delete base;
		delete cat;
	}
	return (0);
}