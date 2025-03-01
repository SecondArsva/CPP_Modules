#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // Prueba de creación y eliminación básica
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;  // No debe haber memory leaks
    delete i;

    std::cout << "--------------------------------" << std::endl;

    // Prueba de array de animales
    Animal *animals[6];

    for (int i = 0; i < 3; i++)
        animals[i] = new Dog();
    for (int i = 3; i < 6; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 6; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 6; i++)
        delete animals[i];

    std::cout << "--------------------------------" << std::endl;

    // Prueba de copia profunda
    Dog d1;
    d1.setIdeas(0, "I want a bone!");
    Dog d2 = d1;  // Constructor de copia

    std::cout << "Dog 1 idea: " << d1.getIdeas(0) << std::endl;
    std::cout << "Dog 2 idea: " << d2.getIdeas(0) << std::endl;

    return 0;
}
