# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:36:20 by ysibous           #+#    #+#              #
#    Updated: 2018/04/27 17:46:45 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

FILES = ft_printf.c
FILES += handle_char.c
FILES += handle_wchar_wstr.c
FILES += handle_int.c
FILES += handle_str.c
FILES += parse_init_desc.c
FILES += print_helpers.c

RM = rm -f

SRC = $(addprefix src/, $(FILES))

OBJ = $(SRC:.c=.o)

LIBFT = includes/libft/libft.a

mlibft.a: 
		make -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all