#include "validation.hpp"

void print_error(std::string message)
{
	std::cout << "\033[91m" << "error: " << message << "\033[39m" << std::endl;
}