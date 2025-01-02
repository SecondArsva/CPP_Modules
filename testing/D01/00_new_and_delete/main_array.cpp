#include <iostream>
#include "StudentArray.hpp"

int main(void)
{
	StudentArray *array = new StudentArray[4];

	delete [] array;
	return (0);
}