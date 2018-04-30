# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:36:20 by ysibous           #+#    #+#              #
#    Updated: 2018/04/29 18:35:10 by ysibous          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

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

OBJ = $(SRC:.c=.o)

LIBFT = includes/libft/libft.a

mlibft.a:
		make re -C includes -C libft

$(NAME): mlibft.a
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) *.o
	ranlib $(NAME)

all: $(NAME) clean

clean:
		$(RM) *.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
