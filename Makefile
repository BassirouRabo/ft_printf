# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 22:56:11 by brabo-hi          #+#    #+#              #
#    Updated: 2017/12/24 00:11:44 by brabo-hi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=printf.a
SRC=\
	ft_add.c\
	ft_convert.c\
	ft_find.c\
	ft_get.c\
	ft_help.c\
	ft_helper.c\
	ft_printf.c\
	ft_set1.c\
	ft_set2.c\
	ft_atoi.c\
	ft_isdigit.c\
	ft_itoa_base.c\
	ft_memalloc.c\
	ft_memcpy.c\
	ft_memdel.c\
	ft_memset.c\
	ft_putchar.c\
	ft_putchar_fd.c\
	ft_putstr.c\
	ft_putstr_fd.c\
	ft_strcat.c\
	ft_strdel.c\
	ft_strlen.c\
	ft_strncat.c\
	ft_strnew.c\
	ft_tolower.c\
	ft_toupper.c
FLAGS=-Wextra -Wall -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(FLAGS)
	@ar -rc $(NAME) $(SRC:.c=.o)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(SRC:.c=.o)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f .a

re: fclean all
