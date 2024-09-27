NAME=phonebook

SRC=main.cpp \
	Contact.cpp \
	PhoneBook.cpp \
	read.cpp \
	print.cpp \
	validation.cpp \
	validation_error.cpp


FLAGS=-Wall -Wextra -Werror -std=c++98 -fsanitize=address

all: $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

re: fclean all

fclean:
	rm -f $(NAME)