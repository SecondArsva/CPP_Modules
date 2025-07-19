#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef> // size_t

template<typename T>
void iter(T *array, size_t length, void (*func)(T const &))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif
