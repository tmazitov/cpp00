NAME = megaphone

SRCS = ./megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
SANYA = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)
 
clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re