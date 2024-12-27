#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample
{
	public:
		
		int	publicFoo;
		void	publicBar(void)const;

		Sample();
		~Sample();

	private:

		int	_privateFoo;
		void	_privateBar(void)const;
};

#endif
