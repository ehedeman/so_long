# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 13:09:29 by ehedeman          #+#    #+#              #
#    Updated: 2024/01/25 12:38:14 by ehedeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_strlen.c				\
		ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_strlcpy.c			\
		ft_strlcat.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strncmp.c			\
		ft_memchr.c				\
		ft_strnstr.c			\
		ft_atoi.c				\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_memcmp.c				\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_strmapi.c			\
		ft_striteri.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_itoa.c				\
		get_next_line_bonus.c	\
		get_next_line_utils.c	\
		ft_print_hex.c			\
		ft_print_nbr.c			\
		ft_print_ptr.c			\
		ft_print_str.c			\
		ft_print_unsigned.c		\
		ft_printf.c				\
		ft_itoa_print.c	

SRC_DIR = src/
#SRC_PREF = $(addprefix $(SRC_DIR), $(SRC))

NAME = libft.a

OBJS_DIR = objs/
OBJS = $(SRC:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar -rc $(NAME) $(OBJECTS_PREFIXED) 
#	@echo "Done :D"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re