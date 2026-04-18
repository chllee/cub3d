CC = cc
CFLAGS = -Wextra -Werror -Wall

NAME = libftgnl.a

DEPS = get_next_line.h
SRC = get_next_line_utils.c get_next_line.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re