#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "color.hpp"

void print_greetings()
{
	std::cout << "Welcome to the PhoneBook!" << std::endl;
}

void print_commands()
{
	std::cout << "Commands:" << std::endl;
	std::cout << "-" << GREEN	<< "ADD"	<< RESET << " - add contact" << std::endl;
	std::cout << "-" << BLUE	<< "SEARCH" << RESET << " - search contact" << std::endl;
	// std::cout << "-" << YELLOW	<< "TEST"	<< RESET << " - test phone book" << std::endl;
	std::cout << "-" << RED		<< "EXIT"	<< RESET << " - exit the program" << std::endl;
}

bool is_command(std::string command)
{
	bool is_command;

	is_command = command == "ADD" 
	|| command == "SEARCH"
	// || command == "TEST" 
	|| command == "EXIT";

	if (!is_command)
	{
		print_error("invalid command");
		return false;
	}

	return true;
}

int main()
{
	PhoneBook*		phoneBook;
	std::string		command;

	print_greetings();
	phoneBook = new PhoneBook();
	while(1) 
	{
		print_commands();
		command = repeatable_read("Enter command: ", is_command, -1);
		if (command.empty())
			break;
		else if (command == "ADD")
			phoneBook->addContact();
		else if (command == "SEARCH")
			phoneBook->searchContact();
		else if (command == "EXIT")
			break;
		// else if (command == "TEST")
		// 	phoneBook->test();		 
	}

	return 0;
}