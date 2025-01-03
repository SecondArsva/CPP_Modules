#include "Zombie.hpp"

int main(void)
{
	std::string zombie1Name;
	std::string zombie2Name;
	std::string zombie3Name;
	std::string zombie4Name;
	std::string response;

	
	std::cout << "The exercise allows us to see when we need to allocate classes." << std::endl;
	std::cout << std::endl;
	std::cout << "First function 'newZombie' must allocate a Zombie class instance for use it in the future." << std::endl;
	std::cout << std::endl;
	std::cout << "Let's create three zombies that will be allocated in memory." << std::endl;
	std::cout << std::endl;
	std::cout << "First Zombie's name: ";
	std::cin >> zombie1Name;
	std::cout << std::endl;
	std::cout << "Second Zombie's name: ";
	std::cin >> zombie2Name;
	std::cout << std::endl;
	std::cout << "Third Zombie's name: ";
	std::cin >> zombie3Name;
	std::cout << std::endl;
	Zombie *zombie1Instance = newZombie(zombie1Name);
	Zombie *zombie2Instance = newZombie(zombie2Name);
	Zombie *zombie3Instance = newZombie(zombie3Name);
	std::cout << "Hi, all!" << std::endl;
	std::cout << std::endl;
	std::cout << "Say something, " << zombie1Instance->getName() << "!"<< std::endl;
	zombie1Instance->announce();
	std::cout << std::endl;
	std::cout << "Now the remaining two!" << std::endl;
	std::cout << std::endl;
	zombie2Instance->announce();
	zombie3Instance->announce();
	std::cout << std::endl;

	std::cout << "Second function 'randomChump' create a non-allocated Zombie instance to salute us!" << std::endl;
	std::cout << std::endl;
	std::cout << "Non-allocated Zombie's name: ";
	std::cin >> zombie4Name;
	randomChump(zombie4Name);
	std::cout << std::endl;
	std::cout << "A non-allocated zombie destroys himself when the function that contains it in its scope ends." << std::endl;
	std::cout << std::endl;


	std::cout << "Do you want to blow up the heads of " << zombie1Instance->getName() << ", " << zombie2Instance->getName() << " and " << zombie3Instance->getName() << "?" << std::endl;
	std::cout << "(Type 'YES' to press the trigger of your awesome triple barrel auto-aimmed dragon's breath shotgun)" << std::endl;
	std::cout << std::endl;
	std::cout << "Your respose: ";
	std::cin >> response;
	if (!response.compare("YES"))
	{
		delete zombie1Instance;
		delete zombie2Instance;
		delete zombie3Instance;
	}
	return (0);
}