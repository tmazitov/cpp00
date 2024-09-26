#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>

// VALIDATE FUNCTIONS

bool is_empty(std::string str);
bool is_letters_only(std::string str);
bool is_digits_only(std::string str);
bool is_letters_and_digits(std::string str);
bool is_any(std::string str);

// PRINT ERROR

void print_error(std::string message);

#endif