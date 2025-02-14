#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal *meta = new Animal(); // Unknown base type
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound(); //will output the cat sound!
	}
	std::cout << std::endl;
	{
		const WrongAnimal *wrongBase = new WrongAnimal();
		const WrongAnimal *wrongCat = new WrongCat();

		std::cout << wrongBase->getType() << " " << std::endl;
		std::cout << wrongCat->getType() << " " << std::endl;
		wrongBase->makeSound();
		wrongCat->makeSound();
	}

	return (0);
}