#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook*		phoneBook = new PhoneBook();;
	std::string		command;

	Console.printGreetings();
	Console.printCommands();
	command = repeatable_read("Enter command: ", is_command, -1);
	while(command.empty() || command != "EXIT") 
	{
		switch (command)
		{
		case "ADD":
			phoneBook->addContact();
			break;
		case "SEARCH":
			phoneBook->searchContact();
			break;
		case "TEST":
			if (IS_IMPROVED) 
			{
				phoneBook->test();
			}
			break;
		default:
			break;
		}
		Console.printCommands();
		command = repeatable_read("Enter command: ", is_command, -1);
	}

	return 0;
}