#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T &a, T &b)
{
	T aux = a;
	
	a = b;
	b = aux;
}

template<typename T>
T const &min(T const &a, T const &b)
{
	if (a == b)
		return (b);
	else if (a < b)
		return (a);
	else
		return (b);
}

template<typename T>
T const &max(T const &a, T const &b)
{
	if (a == b)
		return (b);
	else if (a > b)
		return (a);
	else
		return (b);
}

#endif
