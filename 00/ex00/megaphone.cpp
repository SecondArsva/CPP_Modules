#include <iostream> // cout (stdoutprint)
#include <cctype> // toupper

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		
		for (int j = 0; j < (int)str.length(); j++)
			std::cout << static_cast<char>(std::toupper(str[j]));
	}
	std::cout << std::endl;
	return (0);
}