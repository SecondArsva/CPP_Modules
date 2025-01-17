#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream>
# include <string>

class Sample
{
	public:

		void bar(char const c)const;
		void bar(int const n)const;
		void bar(float const z)const;
		void bar(Sample const &i)const;

		Sample();
		~Sample();
};

#endif