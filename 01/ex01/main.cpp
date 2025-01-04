#include "Zombie.hpp"

int main(void)
{
	int			N = 9;
	std::string	name = "Miguelet";
	Zombie *horde = zombieHorde(N, name);

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}