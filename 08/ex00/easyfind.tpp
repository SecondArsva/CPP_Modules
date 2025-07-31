#ifndef EASYFIND_TPP
# define EASYFIND_TPP

template<typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), to_find)
	if (if == container.end())
		throw std::runtime_error("Not found");
	return (it)
}

#endif