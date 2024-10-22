#include "PhoneBook.hpp"
#include <stdlib.h>
#include <cstdio>

PhoneBook::PhoneBook()
{
	this->addedContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::searchContact()
{
	if (this->addedContacts == 0) {
		std::cout << "/* You see the empty list     */" << std::endl;
		std::cout << "/* and it's nothing to search */" << std::endl;
		return ;
	}
	this->printContactTable();
	std::string index = Console.repeatableRead("Write contact index: ", is_digits_only);
	if (index.empty())
		return;
	int contactIndex = std::atoi(index.c_str());
	
	if (contactIndex <= 0 || contactIndex > this->addedContacts)
	{
		Console.panic("index of contact is not exists");
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i]->getIndex() == contactIndex)
		{
			this->contacts[i]->printInDetails();
			return;
		}
	}
	Console.panic("index of contact is not exists");
}

void PhoneBook::addContact()
{
	int contactIndex = this->addedContacts % 8;
	Contact* contact = new Contact();

	std::string firstName = Console.repeatableRead("First name: ", Console.isLetterOnly);
	if (firstName.empty())
		return;
	std::string lastName = Console.repeatableRead("Last name: ", Console.isLetterOnly);
	if (lastName.empty())
		return;
	std::string nickName = Console.repeatableRead("Nick name: ", Console.isLetterAndDigits);
	if (nickName.empty())
		return;
	std::string phoneNumber = Console.repeatableRead("Phone number: ", Console.isDigitsOnly);
	if (phoneNumber.empty())
		return;
	std::string secret = Console.repeatableRead("Secret: ", Console.isAny);
	if (secret.empty())
		return;

	contact->setIndex(this->addedContacts + 1);
	contact->setFirstName(firstName);
	contact->setLastName(lastName);
	contact->setNickName(nickName);
	contact->setPhoneNumber(phoneNumber);
	contact->setSecret(secret);

	this->contacts[contactIndex] = contact;
	this->addedContacts++;
}

void PhoneBook::printContactTable()
{
	Contact.printHorizontalLine(51);
	std::cout << "|";
	Contact.printColumn("Index");
	Contact.printColumn("First name");
	Contact.printColumn("Last name");
	Contact.printColumn("Nick name");
	std::cout << std::endl;
	Contact.printHorizontalLine(51);

	for (int i = 0; i < std::min(this->addedContacts, 8); i++)
	{
		std::cout << "|";
		this->contacts[i]->printAsTableRow();
		std::cout << std::endl;
	}
	Contact.printHorizontalLine(51);
}

static std::string toString(int num) {
	char buffer[20]; // Assuming the integer is not too large
	std::sprintf(buffer, "%d", num);
	return std::string(buffer);
}

void PhoneBook::test()
{
	int id;
	std::string str;

	if (this->addedContacts >= 8) {
		std::cout << "Nothing is changed..." << std::endl;
		return ;
	}

	std::cout << YELLOW << "Let's add some test contacts..." << RESET << std::endl;

	for (int i = this->addedContacts; i < 8; i++)
	{
		Contact* contact = new Contact();
		id = i + 1;
		str = toString(id);
		contact->setIndex(id);
		contact->setFirstName("First" + str);
		contact->setLastName("Last" + str);
		contact->setNickName("Nick" + str);
		contact->setPhoneNumber("Phone" + str);
		contact->setSecret("Secret" + str);
		this->contacts[i] = contact;
		this->addedContacts++;
	}
}