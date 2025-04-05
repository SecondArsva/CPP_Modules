#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool	_signed;
		int const	_signGrade;
		int const	_execGrade;
	public:
		AForm();
		AForm(AForm const &src);
		AForm &operator=(AForm const &rhs);
		~AForm();

		AForm(std::string const name, int const signGrade, int const execGrade);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("exception: grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("exception: grade is too low");
				}
		};

		std::string getName()const;
		bool getSigned()const;
		int getSignGrade()const;
		int getExecGrade()const;
		
		void beSigned(Bureaucrat const &signer);

		virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &rhs);

#endif