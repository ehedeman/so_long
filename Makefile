# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 13:51:06 by ehedeman          #+#    #+#              #
#    Updated: 2024/03/04 12:11:07 by ehedeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
SRC = 	so_long.c		\
		error.c			\
		map_handling.c	\
		map_init.c		\
		player.c		\
		key_handling.c	\
		init.c			\
		put_to_window.c	\
		objects.c		\
		map_validation.c\
		exit.c			\
		wall.c			\
		possible_path.c
		

OBJS = $(SRC:.c=.o)
OBJS_DIR = objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
#KILL = kill
#SRC_K = kill.c

CC = cc 
CFLAGS = -Werror -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer

LIBFT = libft.a
LIB_PATH = ./libft/

all: $(LIBFT) $(CLIENT) $(NAME) #norm
	@printf "\e[38;5;118mLibft.a Done :D\n"
	@printf "\e[38;5;118mServer Done :D\n"
	@printf "\e[38;5;118mClient Done :D\n"

$(NAME): $(OBJS_PREFIXED)
	@$(CC) $(CFLAGS) $(OBJS_PREFIXED) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Ilibft -L$(LIB_PATH) -lft -o $(NAME)

$(OBJS_DIR)%.o : %.c so_long.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	@(cd libft && make all)

clean:
	@rm -rf $(OBJS_DIR)
	@(cd libft && make clean)
	@printf "\e[033;31mRemoved object Files\n"

fclean: clean
	@(cd libft && make fclean)
	@printf "\e[033;31mRemoved libft.a\n"
	@rm -f $(NAME)
#	@rm -f $(KILL)
	@printf "\e[033;31mRemoved binary\n"

re: fclean all

leaks:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes ./so_long map.txt

norm:
	@norminette $(SRC) so_long.h

.PHONY: all clean re fclean leaks norm
