#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream>

class Sample
{
	public:

		Sample(void);							//Canonical Form
		Sample(int const n);
		Sample(Sample const &src);				//Canonical Form
		~Sample(void);							//Canonical Form

		Sample &operator=(Sample const &rhs);	//Canonical Form

		int getValue(void)const;

	private:

		int _foo;
};

/* "string-sificación" de la clase.
   Serialización de la clase a string para debugging.
   No forma parte de la Canonical Form, pero puede ser útil. */
std::ostream &operator<<(std::ostream &o, Sample const &i);

#endif
