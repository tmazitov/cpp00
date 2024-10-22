
#include "Contact.hpp"
#include <iostream>
#include <cstdio>   // For sprintf

std::string toString(int num) {
	char buffer[20]; // Assuming the integer is not too large
	std::sprintf(buffer, "%d", num);
	return std::string(buffer);
}

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	this->lastName = lastName;
}

void Contact::setIndex(int index) {
	this->index = index;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setSecret(const std::string& secret) {
	this->secret = secret;
}

void Contact::setNickName(const std::string& nickName) {
	this->nickName = nickName;
}

int Contact::getIndex() const {
	return index;
}

void Contact::printAsTableRow() const {
	Console::printColumn(toString(index));
	Console::printColumn(firstName);
	Console::printColumn(lastName);
	Console::printColumn(nickName);
}

void Contact::printInDetails() const {
	std::cout << "- First name: " << firstName << std::endl;
	std::cout << "- Last name: " << lastName << std::endl;
	std::cout << "- Nick name: " << nickName << std::endl;
	std::cout << "- Phone number: " << phoneNumber << std::endl;
}