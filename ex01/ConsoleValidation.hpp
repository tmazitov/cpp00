#ifndef CONSOLE_VALIDATION_HPP
# define CONSOLE_VALIDATION_HPP

# include <iostream>

class ConsoleValidation {
	public:
		static bool isAny(std::string str);
		static bool isLettersAndDigits(std::string str);
		static bool isDigitsOnly(std::string str);
		static bool isLettersOnly(std::string str);
		static bool isEmpty(std::string str);
		static bool isDigit(char c);
		static bool isLetter(char c);
		static void panic(std::string message);
};

#endif // !CONSOLE_VALIDATION_HPP