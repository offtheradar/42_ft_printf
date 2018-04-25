# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:36:20 by ysibous           #+#    #+#              #
#    Updated: 2018/04/25 10:43:09 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main
CC = gcc
CFLAGS = -Wall -Wextra  -o

FILES = ft_printf.c
FILES += handle_char.c
FILES += handle_int.c
FILES += handle_long.c
FILES += handle_str.c
FILES += parse_init_desc.c

SRC = $(addprefix src/, $(FILES))

all: $(NAME)

LIBFT = includes/libft/libft.a

mlibft.a: 
		make -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(NAME) $(SRC) $(LIBFT)