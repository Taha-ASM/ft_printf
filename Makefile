NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ./ft_putnbr.c ./ft_printf.c ./ft_putchar.c ./ft_putstr.c ./ft_puthex.c \
	./ft_unsigned.c ./ft_hex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re