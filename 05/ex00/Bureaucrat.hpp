#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

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
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		void incrementGrade();
		void decrementGrade();
		
};

/* Sobrecarga del operador << como función no miembro:
 * -----------------------------------------------
 * - No puede ser un método de la clase porque el primer operando
 *   (std::ostream) no es un miembro de Bureaucrat.
 * - Se define fuera de la clase para seguir la convención estándar
 *   de sobrecarga de operadores.
 */
std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs);

#endif