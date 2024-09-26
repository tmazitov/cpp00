#include <iostream>
#include "read.hpp"

std::string repeatable_read(std::string placeholder, bool (*validator)(std::string), int max_tries)
{
	std::string input;
	int i = 0;
	bool is_infinity = max_tries == -1;
	
	while (i < max_tries || is_infinity)
	{
		std::cout << placeholder;
		std::cin >> input;
		if (!is_empty(input) && validator(input))
			return input;
		i++;
	}
	return "";
}