# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 08:44:23 by vviovi            #+#    #+#              #
#    Updated: 2022/11/17 11:06:24 by vviovi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CC = clang

NAME = so_long

SRC = 	main.c

LIBFTFLAGS = -Llibft -lft

INCLUDES = -I. -Ilibft

OBJ = ${SRC:.c=.o}

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd libft && make
	@echo "╔═════════════════╗"
	@echo "║Compiling so_long║"
	@echo "╚═════════════════╝"
	@$(CC) $(OBJ) $(LIBFTFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	@echo "╔════════════════╗"
	@echo "║Cleaning so_long║"
	@echo "╚════════════════╝"
	@rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

.PHONY: clean fclean re all
