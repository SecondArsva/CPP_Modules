#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;	// From 1 to 150. A highest the number lower the rank
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		~Bureaucrat();

		Bureaucrat(std::string const name, int grade);

		std::string getName()const;
		int	getGrade()const;
};

#endif