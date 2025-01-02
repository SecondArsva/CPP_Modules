#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <iostream>

class StudentArray
{
	public:

		std::string	studentName;
		int			id;
		static int	total;
		StudentArray();
		~StudentArray();
};

#endif