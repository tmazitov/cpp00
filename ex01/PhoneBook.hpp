#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib> // For atoi
#include "Contact.hpp"
#include "Console.hpp"


class PhoneBook {
private:
	int			addedContacts;
	Contact*	contacts[8];

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContact();
	
	void printContactTable();
	void test();
};

#endif // PHONEBOOK_HPP