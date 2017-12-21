NAME=libftprintf.a
SRC=*.c
LIBFT=libft/*.c
FLAGS=-Wextra -Wall -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(LIBFT)
	@ar -rc $(NAME) $(SRC:.c=.o)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(SRC:.c=.o)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a

re: fclean all
