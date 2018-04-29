# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:36:20 by ysibous           #+#    #+#              #
#    Updated: 2018/04/28 18:54:43 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra

FILES = ft_printf.c
FILES += handle_char.c
FILES += handle_wchar_wstr.c
FILES += handle_int.c
FILES += handle_str.c
FILES += parse_init_desc.c
FILES += print_helpers.c
FILES += set_flags_len.c
FILES += cast_int.c
FILES += num_len.c

RM = rm -f

SRC = $(addprefix src/, $(FILES))

LIBFT = includes/libft/libft.a

mlibft.a: 
		make -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) $(LIBFT) $(SRC)	

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all