#ifndef READ_HPP
#define READ_HPP

#include <iostream>
#include "validation.hpp"

std::string repeatable_read(std::string placeholder, bool (*validator)(std::string), int repeatCount=3);

#endif