#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample
{
	private:

		int Foo;

	public:
		
		int		getFoo(void)const;
		void	setFoo(int v);

		Sample();
		~Sample();
};

#endif