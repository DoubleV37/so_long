# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 08:44:23 by vviovi            #+#    #+#              #
#    Updated: 2022/11/23 10:38:58 by vviovi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

CC = clang

NAME = so_long

SRC = 	mandatory/main.c \
		mandatory/utils_map.c \
		mandatory/map_verif.c

LIBFTFLAGS = -Llibft -lft

INCLUDES = -I. -Ilibft

OBJ = ${SRC:.c=.o}

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd libft && make
	@echo "╔═════════════════╗"
	@echo "║Compiling so_long║"
	@echo "╚═════════════════╝"
	@$(CC) $(OBJ) $(LIBFTFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	@cd libft && make clean
	@echo "╔════════════════╗"
	@echo "║Cleaning so_long║"
	@echo "╚════════════════╝"
	@rm -f $(OBJ)

fclean : clean
	@cd libft && make fclean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

.PHONY: clean fclean re all
