#include <string>

class Animal
{
	private:
		int	_numberOfLegs;
	
	public:
		Animal();
		Animal(Animal const &src);
		Animal operator=(Animal const &rhs);
		~Animal();

		void	run(int distance);
		void	call();
		void	eat(std::string const &what);
		void	walk(int distance);
};

class Otter : public Animal
{
	public:
		Otter();
		Otter(Otter const &src);
		Otter operator=(Otter const &src);
		~Otter();

		void	scornSomeone(std::string const &target);
};

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &src);
		Cat operator=(Cat const &src);
		~Cat();

		void	scornSomeone(std::string const &target);
};

class Pony : public Animal
{
	public:
		Pony();
		Pony(Pony const &src);
		Pony operator=(Pony const &rhs);
		~Pony();

		void	doMagic(std::string const &target);
		void	run(int distance); // replace the Animal.run member function
};