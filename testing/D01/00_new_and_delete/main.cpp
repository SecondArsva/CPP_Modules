#include <iostream>
#include "Student.hpp"

int main(void)
{
	Student automaticStack("Jak");
	Student *dynamicHeap = new Student("Daxter");

	// allocated classes must be deleted (freed)
	delete dynamicHeap;

	// non-allocated classes are "destroyed" with the end of the scoped function
	return (0);
}