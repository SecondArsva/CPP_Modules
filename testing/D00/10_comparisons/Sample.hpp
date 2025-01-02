#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample
{
	public:

		int	getFoo(void)const;
		int	compareFoo(Sample *other)const;

		Sample(int v);
		~Sample();
	
	private:

		int _foo;
};

#endif
