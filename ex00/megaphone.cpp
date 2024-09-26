
#include <iostream>

bool is_small_letter(char c) 
{
	return (c >= 'a' && c <= 'z');
}

void sound_megaphone(std::string message)
{
	int	counter;
	int length;

	length = message.length();
	if (length == 0)
		return ;
	counter = 0;
	while (counter < length)
	{
		if (is_small_letter(message[counter]))
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
			sound_megaphone(argv[i]);
		}
		std::cout << std::endl;
	}
}