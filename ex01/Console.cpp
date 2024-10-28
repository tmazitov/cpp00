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

void Console::printHorizontalLine()
{
	int colWidth = 10;

	std::cout << "+" << std::setfill('-') << std::setw(colWidth) << ""
				<< "+" << std::setw(colWidth) << ""
				<< "+" << std::setw(colWidth) << ""
				<< "+" << std::setw(colWidth) << "" << "+" << std::endl;
}

void Console::printColumn(std::string content)
{ 
	const int colWidth = 10;
	int length = content.length();
	std::cout << std::left;
	std::cout << std::setw(colWidth);
	if (length > colWidth)
	{
		std::string trunkedValue = content.substr(0, colWidth - 1) + ".";
		std::cout << trunkedValue;
	}
	else
	{
		std::cout << std::setfill(' ');
		std::cout << content;
	}
	std::cout << "|";
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

