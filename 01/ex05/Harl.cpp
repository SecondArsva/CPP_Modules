#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	typedef void (Harl::*MemberFunctionsPtr)();
	size_t				pos;
	std::string			levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	MemberFunctionsPtr	actions[] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	
	for (pos = 0; pos < 4; pos++)
	{
		if (level == levels[pos])
		{
			(this->*actions[pos])();
			return ;
		}
	}
	std::cout << "Invalid level" << std::endl;
}

void Harl::_debug(){std::cout << "Debug message" << std::endl;}

void Harl::_info(){std::cout << "Info message" << std::endl;}

void Harl::_warning(){std::cout << "Warning message" << std::endl;}

void Harl::_error(){std::cout << "Error message" << std::endl;}

Harl::Harl(){}

Harl::~Harl(){}