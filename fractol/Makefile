# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 21:57:19 by elfetoua          #+#    #+#              #
#    Updated: 2020/03/06 17:21:22 by elfetoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
SRC = main.c setup.c fractals.c events.c
OBJ = $(SRC:.c=.o)
INCLUDE = fractal.h
LIBFT = ./libft/libft.a
LDLIBS = -lft -lm -lmlx -lpthread
LDFLAGS = -L./libft -framework OpenGl -framework Appkit
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 

all: $(LIBFT) $(NAME) clean

$(LIBFT):
	make -C libft
$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
	make clean -C libft
fclean:clean
	$(RM) $(NAME)
	make fclean -C libft
re: fclean all
