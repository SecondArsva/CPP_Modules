#ifndef STUDENT_HPP
# define STUDENT_HPP

# include <iostream>

class Student
{
	public:

		std::string studentName;
		Student(std::string name);
		~Student();
};

#endif