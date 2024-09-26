#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->addedContacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::searchContact()
{
	this->printContactTable();
	std::string index = repeatable_read("Write contact index: ", is_digits_only);
	if (index.empty())
		return;
	int contactIndex = std::atoi(index.c_str());
	if (contactIndex < 0 || contactIndex >= this->addedContacts)
	{
		print_error("invalid index");
		return;
	}
	// this->contacts[contactIndex]->print();
}

void PhoneBook::addContact()
{
	static int index = 0;
	int contactIndex = index % 8;
	Contact* contact = new Contact();

	std::string firstName = repeatable_read("First name: ", is_letters_only);
	if (firstName.empty())
		return;
	std::string lastName = repeatable_read("Last name: ", is_letters_only);
	if (lastName.empty())
		return;
	std::string nickName = repeatable_read("Nick name: ", is_letters_and_digits);
	if (nickName.empty())
		return;
	std::string phoneNumber = repeatable_read("Phone number: ", is_digits_only);
	if (phoneNumber.empty())
		return;
	std::string secret = repeatable_read("Secret: ", is_any);
	if (secret.empty())
		return;

	contact->setIndex(index);
	contact->setFirstName(firstName);
	contact->setLastName(lastName);
	contact->setPhoneNumber(phoneNumber);
	contact->setSecret(secret);

	this->contacts[contactIndex] = contact;

	if (this->addedContacts < 8)
		this->addedContacts++;

	index++;
}

void PhoneBook::printContactTable()
{
	printHorizontalLine(44);
	std::cout << "|";
	printColumn("Index");
	printColumn("First name");
	printColumn("Last name");
	printColumn("Nick name");
	std::cout << std::endl;
	printHorizontalLine(44);
	for (int i = 0; i < this->addedContacts; i++)
	{
		std::cout << "|";
		this->contacts[i]->printAsTableRow();
		std::cout << std::endl;
	}
	printHorizontalLine(44);
}