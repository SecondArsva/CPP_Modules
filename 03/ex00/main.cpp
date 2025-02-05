#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a;
	ClapTrap b("Axton");

	a = b;
	
	ClapTrap claptrap(a);

	claptrap.attack("Badass Psycho");
	claptrap.takeDamage(5);
	claptrap.takeDamage(4);
	claptrap.beRepaired(9);
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.attack("Badass Psycho");
	claptrap.beRepaired(1);
	claptrap.takeDamage(52);
	claptrap.attack("Badass Psycho");
	claptrap.beRepaired(100);
	claptrap.takeDamage(999);

	return (0);
}
