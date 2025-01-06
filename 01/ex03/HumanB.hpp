#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>

# include "Weapon.hpp"

/* HumanB debe tener un puntero a un Weapon ya que el campo no se establece
   en el momento de la creación y el arma puede ser NULL.
*/
class HumanB
{
	private:

		std::string	_name;
		Weapon		*_weapon;

	public:
		
		void		attack(void);

		std::string	getName(void)const;
		void		setName(std::string name);
		Weapon		*getWeapon(void)const;
		void		setWeapon(Weapon &weapon);

		HumanB();
		HumanB(std::string name);
		~HumanB();
};

#endif