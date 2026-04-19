CC      = cc
CFLAGS  = -Wextra -Werror -Wall

NAME    = cub3D

LIBFT_DIR    = ./libft/libft01
FTPRINTF_DIR = ./libft/ft_printf
GNL_DIR      = ./libft/gnl
SRC_DIR      = src
OBJ_DIR      = obj

LIBFT_LIB     = $(LIBFT_DIR)/libft.a
GNL_LIB       = $(GNL_DIR)/libftgnl.a
FT_PRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

MINILIBX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT_FLAGS    = -L$(LIBFT_DIR) -lft
FTPRINTF_FLAGS = -L$(FTPRINTF_DIR) -lftprintf
GNL_FLAGS      = -L$(GNL_DIR) -lftgnl
INCLUDES = -I$(SRC_DIR) \
           -I$(LIBFT_DIR) \
           -I$(FTPRINTF_DIR) \
           -I$(GNL_DIR)

SRC_FILES = z_print_map.c main.c exit_utils.c map_storage.c map_validity.c \
			utils.c file_process.c 

SRC       = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ       = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MINILIBX_FLAGS) $(LIBFT_FLAGS) $(FTPRINTF_FLAGS) $(GNL_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(FT_PRINTF_LIB):
	make -C $(FTPRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re