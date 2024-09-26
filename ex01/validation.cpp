#include "validation.hpp"

bool is_letter(char c) 
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) 
{
	return (c >= '0' && c <= '9');
}

bool is_empty(std::string str) 
{
	if (str.empty())
	{
		print_error("entered value is empty");
		return true;
	}
	return false;
}

bool is_letters_only(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!is_letter(str[i]))
		{
			print_error("only letters are allowed");
			return false;
		}
	}
	return true;
}

bool is_digits_only(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			print_error("only digits are allowed");
			return false;
		}
	}
	return true;
}

bool is_letters_and_digits(std::string str) 
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!is_letter(str[i]) && !is_digit(str[i]))
		{
			print_error("only letters and digits are allowed");
			return false;
		}
	}
	return true;
}

bool is_any(std::string str) 
{
	(void)str;
	return true;
}