#ifndef CONSOLE_HPP
# define CONSOLE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "ConsoleValidation.hpp"

#define RESET "\033[0m"	
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#define IMPROVED true

class Console : public ConsoleValidation {
	public:
		static void printColumn(std::string content);
		static void printHorizontalLine();
		static void printGreetings();
		static void printCommands();
		static bool isCommand(std::string command);
		static std::string repeatableRead(std::string placeholder, bool (*validator)(std::string), int repeatCount=3);
};

#endif