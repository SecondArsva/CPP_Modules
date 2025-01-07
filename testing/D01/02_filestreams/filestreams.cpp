#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream	ifs("numbers");
	unsigned int	dst1;
	unsigned int	dst2;
	unsigned int	dst3;
	unsigned int	dst4;
	unsigned int	dst5;
	ifs >> dst1 >> dst2 >> dst3 >> dst4;
	std::cout << dst1 << " " << dst2 << " " << dst3 << " " << dst4 << " " << dst5 << std::endl;
	ifs.close();
	// -------------------------------------------
	std::ofstream	ofs("test.out");
	ofs << "I like ponies a whole damn lot" << std::endl;
	ofs.close();
	
	return (0);
}