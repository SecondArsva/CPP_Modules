#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:

		std::string	_name;

	public:

		void	announce(void)const;
		
		std::string getName(void)const;
		void		setName(std::string name);

		Zombie();
		Zombie(std::string name);
		~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif