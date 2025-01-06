#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:

		std::string	_type;

	public:
		
		/* La convención más común en C++ coloca la palabra clave "const" antes del tipo.
		   "const std::string &" y "std::string const &" hacen lo mismo.
		   De hecho hay gente que lo coloca después para así ver antes el tipo que
		   devuelve y no liarse leyendo de más por el "const".
		*/
		const std::string &getType(void)const;
		void		setType(std::string type);
		
		Weapon();
		Weapon(std::string type);
		~Weapon();
};

#endif