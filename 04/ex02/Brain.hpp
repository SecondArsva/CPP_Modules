#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(Brain const &src);
		Brain &operator=(Brain const &rhs);
		~Brain();

		std::string getIdeas(int const index)const;
		void setIdeas(int const index, std::string const idea);
};

#endif
