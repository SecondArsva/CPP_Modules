#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain copy assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdeas(int const index)const
{
	if (index < 0 || index > 99)
		return (std::cout << "Error: Ideas's index goes from 0 to 99" << std::endl, "");
	return (this->_ideas[index]);
}

void Brain::setIdeas(int const index, std::string const idea)
{
	if (index < 0 || index > 99)
	{
		std::cout << "Error: Ideas's index goes from 0 to 99" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}
