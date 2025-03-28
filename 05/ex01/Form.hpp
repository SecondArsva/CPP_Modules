#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool	_signed;
		int const	_signGrade;
		int const	_execGrade;
	public:
		Form();
		Form(Form const &src);
		Form &operator=(Form const &rhs);
		~Form();

		Form(std::string const name, int const signGrade, int const execGrade);

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
		
		void beSigned(Bureaucrat const signer);
};

std::ostream &operator<<(std::ostream os, Form const &rhs);

#endif