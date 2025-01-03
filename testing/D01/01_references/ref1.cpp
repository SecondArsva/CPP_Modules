#include <iostream>

int main(void)
{
	int numberOfBalls = 42;
	int *ballsPtr = &numberOfBalls;
	int &ballsRef = numberOfBalls;

	std::cout << numberOfBalls << " "
		<< ballsPtr << " " << *ballsPtr << " "
		<< ballsRef << std::endl;

	*ballsPtr = 21;

	std::cout << numberOfBalls << " "
		<< ballsPtr << " " << *ballsPtr << " "
		<< ballsRef << std::endl;

	ballsRef = 13;

	std::cout << numberOfBalls << " "
		<< ballsPtr << " " << *ballsPtr << " "
		<< ballsRef << std::endl;

	return (0);
}