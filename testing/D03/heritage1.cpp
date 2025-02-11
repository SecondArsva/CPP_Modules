#include <string>

class Cat
{
	private:
		int	_numberOfLegs;
	public:
		Cat();
		Cat(Cat const &src);
		Cat	operator=(Cat const &rhs);
		~Cat();

		void	run(int distance);
		void	scornSomeone(std::string const &target);
};

class Pony
{
	private:
		int	numberOfLegs;
	public:
		Pony();
		Pony(Pony const &src);
		Pony operator=(Pony const &rhs);
		~Pony();

		void	run(int distance);
		void	doMagic(std::string const &target);
};