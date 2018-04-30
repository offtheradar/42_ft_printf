# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysibous <ysibous@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 14:36:20 by ysibous           #+#    #+#              #
#    Updated: 2018/04/30 00:28:38 by ysibous          ###   ########.fr        #
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
LIBF = ft_atoi.c ft_lstiter.c ft_memccpy.c ft_putchar.c ft_putstr_fd.c \
ft_strdup.c ft_strmap.c ft_strnstr.c ft_toupper.c \
ft_bzero.c ft_lstadd.c ft_memchr.c ft_putchar_fd.c ft_strcat.c ft_strequ.c \
ft_strmapi.c ft_strrchr.c ft_isalnum.c ft_lstdel.c ft_memcmp.c ft_putendl.c \
ft_strchr.c ft_striter.c ft_strncat.c ft_isalpha.c \
ft_lstdelone.c ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_striteri.c \
ft_strncmp.c ft_strstr.c ft_isascii.c ft_lstmap.c ft_memdel.c ft_putnbr.c \
ft_strcmp.c ft_strjoin.c ft_strncpy.c ft_strsub.c ft_isdigit.c ft_lstnew.c \
ft_memmove.c ft_putnbr_fd.c ft_strcpy.c ft_strlcat.c ft_strnequ.c \
ft_strtrim.c ft_isprint.c ft_memalloc.c ft_memset.c ft_putstr.c ft_strdel.c \
ft_strlen.c ft_strnew.c ft_tolower.c ft_memcmp.c ft_strsplit.c ft_itoa.c \
ft_get_int_len.c ft_count_words.c ft_word_len.c get_next_line.c \
ft_lst_add_to_end.c ft_free_doublep.c ft_free_lst.c ft_putwchar.c

RM = rm -f

SRC = $(addprefix src/, $(FILES))

LIB = $(addprefix includes/libft/, $(LIBF))

OBJ = $(SRC:.c=.o)

LIBFT = includes/libft/libft.a

#mlibft.a:
#		make re -C includes -C libft

#$(NAME): mlibft.a
#	$(CC) $(CFLAGS) -c $(SRC) $(LIB)
#	ar rcs $(NAME) *.o
#	ranlib $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c src/*.c includes/libft/*.c -I includes -I includes/libft $(LIB)
	ar rcs $(NAME) *.o
	ranlib $(NAME)

all: $(NAME) clean

clean:
		$(RM) *.o

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
