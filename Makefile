NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra -Iinclude/
SRC = src/*.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re

