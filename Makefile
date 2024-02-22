NAME = pushswap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = push_swap.c utils.c fill_stack.c
LIBFT = Libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C Libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	make -C Libft clean

fclean: clean
	rm -f $(NAME)
	make -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
