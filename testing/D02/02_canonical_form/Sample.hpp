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

std::ostream &operator<<(std::ostream &o, Sample const &i);

#endif
