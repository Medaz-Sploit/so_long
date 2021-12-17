# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 19:14:28 by mazoukni          #+#    #+#              #
#    Updated: 2021/12/16 23:40:25 by mazoukni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re
NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = 		ft_isalnum.c ft_memmove.c ft_split.c ft_isspace.c\
			ft_strlen.c ft_substr.c ft_isalpha.c \
			ft_memset.c ft_strchr.c ft_strmapi.c \
			ft_tolower.c ft_isascii.c ft_memccpy.c \
			ft_putchar_fd.c ft_strdup.c ft_strncmp.c    \
			ft_toupper.c ft_atoi.c ft_isdigit.c ft_memchr.c      \
			ft_putendl_fd.c ft_strjoin.c ft_strnstr.c ft_bzero.c       \
			ft_isprint.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c     \
			ft_strrchr.c ft_calloc.c ft_itoa.c ft_memcpy.c \
			ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c \
			ft_insert_element.c	

OBJ =		$(SRC:.c=.o)

all : $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)
	ranlib	$(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f *.o

re: fclean all
