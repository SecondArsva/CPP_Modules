#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>

# include "Weapon.hpp"

/* Lo ideal sería implementar "_weapon" como referencia,
   ya que su Weapon existe desde la creación hasta la
   destrucción de la instancia, y nunca cambia.
*/
class HumanA
{
	private:

		std::string	_name;
		Weapon		&_weapon; // Referencia al arma

	public:
		
		void		attack(void);

		std::string	getName(void)const;
		void		setName(std::string name);
		Weapon		getWeapon(void)const;
		void		setWeapon(Weapon &weapon);

		//HumanA();
		HumanA(std::string name, Weapon &weapon); // Tipo de parámetro "referencia".
		~HumanA();
};

#endif