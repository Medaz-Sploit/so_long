NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = src/*


all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

