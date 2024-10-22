#include "ConsoleValidation.hpp"

bool ConsoleValidation::isLetter(char c) 
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool ConsoleValidation::isDigit(char c) 
{
	return (c >= '0' && c <= '9');
}

bool ConsoleValidation::isEmpty(std::string str) 
{
	if (str.empty())
	{
		ConsoleValidation.panic("entered value is empty");
		return true;
	}
	return false;
}

bool ConsoleValidation::isLettersOnly(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!is_letter(str[i]))
		{
			ConsoleValidation.panic("only letters are allowed");
			return false;
		}
	}
	return true;
}

bool ConsoleValidation::isDigitsOnly(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			ConsoleValidation.panic("only digits are allowed");
			return false;
		}
	}
	return true;
}

bool ConsoleValidation::isLettersOnly(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!is_letter(str[i]) && !is_digit(str[i]))
		{
			ConsoleValidation.panic("only letters and digits are allowed");
			return false;
		}
	}
	return true;
}

bool ConsoleValidation::isAny(std::string str)
{
	(void)str;
	return true;
}

void panic(std::string message)
{
	std::cout << "\033[91m" << "error: " << message << "\033[39m" << std::endl;
}