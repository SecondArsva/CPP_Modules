#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	//AAnimal *base = new AAnimal(); // You cant instantiate an abstract class, its not allowed
	AAnimal *cat = new Cat();
	AAnimal *dog = new Dog();

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;
}
