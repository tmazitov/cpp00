#include "Console.hpp"

std::string Console::repeatableRead(std::string placeholder, bool (*validator)(std::string), int max_tries)
{
	std::string input;
	int i = 0;
	bool is_infinity = max_tries == -1;
	
	while (i < max_tries || is_infinity)
	{
		std::cout << placeholder;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.bad())
			return "";
		if (!Console::isEmpty(input) && validator(input))
			return input;
		i++;
	}
	return "";
}

int Console::printHorizontalLine(int length)
{
	std::cout << "|";
	for (int i = 0; i < length; i++)
	{
		std::cout << "-";
	}
	std::cout << "|" << std::endl;

	return length;
}

int Console::printColumn(std::string content)
{ 
	const int columnWidth = 10;
	int length = content.length();

	std::cout << " ";
	if (length > columnWidth)
	{
		std::cout << content.substr(0, columnWidth - 1) << ".";
	}
	else
	{
		std::cout << content;
		for (int i = 0; i < columnWidth - length; i++)
		{
			std::cout << " ";
		}
	}
	std::cout << " |";

	return length;
}

void Console::printGreetings()
{
	std::cout << "Welcome to the PhoneBook!" << std::endl;
}

void Console::printCommands()
{
	std::cout << "Commands:" << std::endl;
	std::cout << "-" << GREEN	<< "ADD"	<< RESET << " - add contact" << std::endl;
	std::cout << "-" << BLUE	<< "SEARCH" << RESET << " - search contact" << std::endl;
	if (IMPROVED) {
		std::cout << "-" << YELLOW	<< "TEST"	<< RESET << " - test phone book" << std::endl;
	}
	std::cout << "-" << RED		<< "EXIT"	<< RESET << " - exit the program" << std::endl;
}

bool Console::isCommand(std::string command)
{
	bool isCommand;

	isCommand = command == "ADD" 
	|| command == "SEARCH"
	|| (IMPROVED && command == "TEST") 
	|| command == "EXIT";

	if (!isCommand)
	{
		panic("invalid command");
		return false;
	}

	return true;
}

