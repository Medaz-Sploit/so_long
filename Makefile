NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra 
LIB = -lmlx -framework appkit -framework opengl -D BUFFER_SIZE=1000 
SRC = src/*.c src/libft/*.c src/get_next_line/*.c 
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(LIB) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re

