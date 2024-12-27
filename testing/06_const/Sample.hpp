#ifndef SAMPLE_HPP
# define SAMPLE_HPP

class Sample
{
	public:

		float const	pi;
		int			qd;

		Sample(float const f);
		~Sample();

		void bar(void) const;
};

#endif