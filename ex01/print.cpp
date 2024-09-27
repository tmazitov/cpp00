#include "print.hpp"

int printHorizontalLine(int length)
{
	std::cout << "|";
	for (int i = 0; i < length; i++)
	{
		std::cout << "-";
	}
	std::cout << "|" << std::endl;

	return length;
}

int printColumn(std::string content)
{ 
	const int columnWidth = 10;
	int length = content.length();

	std::cout << " ";
	if (length > columnWidth)
	{
		std::cout << content.substr(0, columnWidth - 1) << ".";
	}
	else
	{
		std::cout << content;
		for (int i = 0; i < columnWidth - length; i++)
		{
			std::cout << " ";
		}
	}
	std::cout << " |";

	return length;
}