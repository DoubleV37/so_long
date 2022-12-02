# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vviovi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 08:44:23 by vviovi            #+#    #+#              #
#    Updated: 2022/12/02 10:56:56 by vviovi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

CC = clang

NAME = so_long

SRC = 	mandatory/main.c \
		mandatory/utils_map.c \
		mandatory/utils_2_map.c \
		mandatory/map_verif.c \
		mandatory/clean_solong.c \
		mandatory/load_assets.c \
		mandatory/player_mvt.c \
		mandatory/utils_mvt.c \
		mandatory/utils_win.c \
		mandatory/map_solv.c

SRC_BONUS = 	bonus/main_bonus.c \
				bonus/utils_map_bonus.c \
				bonus/utils_2_map_bonus.c \
				bonus/map_verif_bonus.c \
				bonus/clean_solong_bonus.c \
				bonus/load_assets_bonus.c \
				bonus/player_mvt_bonus.c \
				bonus/utils_mvt_bonus.c \
				bonus/utils_win_bonus.c \
				bonus/map_solv_bonus.c \
				bonus/animation_bonus.c \
				bonus/ennemy_mvt_bonus.c

LIBFTFLAGS = -Llibft -lft

INCLUDES = -I. -Ilibft

ifdef BONUS
		SRC = $(SRC_BONUS)
endif

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@cd libft && make
	@echo "╔═══════════════════╗"
	@echo "║ Compiling so_long ║"
	@echo "╚═══════════════════╝"
	@$(CC) $(OBJ) $(LIBFTFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	@cd libft && make clean
	@echo "╔══════════════════╗"
	@echo "║ Cleaning so_long ║"
	@echo "╚══════════════════╝"
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	@cd libft && make fclean
	rm -f $(NAME)

re : fclean all

all : $(NAME)

bonus :
	@echo "╔════════════════╗"
	@echo "║ BONUS  so_long ║"
	@echo "╚════════════════╝"
	@make BONUS=1

.PHONY: clean fclean re all bonus
