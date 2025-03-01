#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	//Animal *base = new Animal(); // You cant instantiate an abstract class, its not allowed
	Animal *cat = new Cat();
	Animal *dog = new Dog();

	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();

	delete cat;
	delete dog;
}
