#include <iostream>
#include "Sample1.hpp"
#include "Sample2.hpp"

int main(void)
{
	Sample1 instance1;
	Sample2 instance2;

	instance1.bar();
	instance2.bar();

	return (0);
}