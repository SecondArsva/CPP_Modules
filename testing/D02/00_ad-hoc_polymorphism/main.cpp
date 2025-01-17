#include "Sample.hpp"

int main(void)
{
	Sample instance;

	instance.bar(3.14f);
	instance.bar(42);
	instance.bar('a');
	instance.bar(instance);
	return (0);
}