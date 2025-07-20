#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <cstddef> // size_t

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(Array const &src);
		Array(unsigned int n);
		~Array();

		Array &operator=(Array const &rhs);
		T &operator[](unsigned int index);
		T const &operator[](unsigned int index)const;
		unsigned int size() const;
};

# include "Array.tpp"

#endif
