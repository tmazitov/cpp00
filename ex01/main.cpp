#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook*		phoneBook = new PhoneBook();;
	std::string		command;

	Console::printGreetings();
	Console::printCommands();
	command = Console::repeatableRead("Enter command: ", Console::isCommand, -1);
	while(!(command.empty() || command == "EXIT")) 
	{
		if (command == "ADD") 
		{
			phoneBook->addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook->searchContact();
		}
		else if (IMPROVED && command == "TEST")
		{
			phoneBook->test();
		}
		Console::printCommands();
		command = Console::repeatableRead("Enter command: ", Console::isCommand, -1);
	}

	return 0;
}