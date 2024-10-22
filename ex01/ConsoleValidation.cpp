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
		panic("entered value is empty");
		return true;
	}
	return false;
}

bool ConsoleValidation::isLettersAndDigits(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isLetter(str[i]) && !isDigit(str[i]))
		{
			panic("only letters are allowed");
			return false;
		}
	}
	return true;
}

bool ConsoleValidation::isLettersOnly(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isLetter(str[i]))
		{
			panic("only letters are allowed");
			return false;
		}
	}
	return true;
}

bool ConsoleValidation::isDigitsOnly(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isDigit(str[i]))
		{
			panic("only digits are allowed");
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

void ConsoleValidation::panic(std::string message)
{
	std::cout << "\033[91m" << "error: " << message << "\033[39m" << std::endl;
}