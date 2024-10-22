
#include <iostream>

bool isSmallLetter(char c) 
{
	return (c >= 'a' && c <= 'z');
}

void soundMegaphone(std::string message)
{
	int	counter;
	int length;

	length = message.length();
	if (length == 0)
		return ;
	counter = 0;
	while (counter < length)
	{
		if (isSmallLetter(message[counter]))
			std::cout << (char)(message[counter] - 32);
		else
			std::cout << message[counter];
		counter++;
	}
}

int main(int argc, char **argv){
	if (argc == 1) 
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			soundMegaphone(argv[i]);
		}
		std::cout << std::endl;
	}
}