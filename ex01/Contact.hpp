#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include "print.hpp"

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		int index;
		std::string phoneNumber;
		std::string secret;

	public:
		Contact();
		~Contact();

		void setIndex(int index);
		void setNickName(const std::string& nickName);
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setPhoneNumber(const std::string& phoneNumber);
		void setSecret(const std::string& secret);

		int getIndex() const;
		void printAsTableRow() const;
		void printInDetails() const;
};

#endif // CONTACT_HPP