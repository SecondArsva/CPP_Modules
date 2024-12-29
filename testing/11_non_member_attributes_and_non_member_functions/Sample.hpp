#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample
{
	public:

		Sample();
		~Sample();

		static int	getNbInst(void);

	private:

		static int _nbFoo;
};

#endif