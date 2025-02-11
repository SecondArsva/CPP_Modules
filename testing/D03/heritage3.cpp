#include <string>

class Quadruped
{
	private:
		std::string	name; // Only accessible from an Quadruped object
	
	protected:
		Leg	legs[4]: // Accessible from an Quadruped or derived object
	
	public:
		void	run(); // Accessible from wherever
};

class Dog : public Quadruped // Can access run() and legs
{

};

int main() // Can only access run();