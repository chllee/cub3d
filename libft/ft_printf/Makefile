CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_DIR = ../libft01
LIBFT_LIB = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

SRC = ft_printf.c ft_characters.c ft_numbers.c common.c ft_hex.c ft_address.c
OBJ = $(SRC:.c=.o)

DEPS = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	cp $(LIBFT_LIB) temp_libft.a
	ar x temp_libft.a
	ar rcs $@ $(OBJ) *.o
	rm -f temp_libft.a *.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

