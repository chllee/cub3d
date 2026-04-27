CC      = cc
CFLAGS  = -Wextra -Werror -Wall

NAME    = cub3D

# --- Directories ---
LIBFT_DIR    = ./libft/libft01
FTPRINTF_DIR = ./libft/ft_printf
GNL_DIR      = ./libft/gnl
SRC          = src
OBJ          = obj

# --- Libraries ---
LIBFT_LIB     = $(LIBFT_DIR)/libft.a
GNL_LIB       = $(GNL_DIR)/libftgnl.a
FT_PRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

# --- Flags ---
MINILIBX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT_FLAGS    = -L$(LIBFT_DIR) -lft
FTPRINTF_FLAGS = -L$(FTPRINTF_DIR) -lftprintf
GNL_FLAGS      = -L$(GNL_DIR) -lftgnl

# --- Automatic Source/Object Discovery ---
# This finds main.c in src/ and everything in src/maps/
SRCS = $(shell find $(SRC) -name "*.c")
# This maps src/maps/file.c to obj/maps/file.o
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

# --- Includes ---
INCLUDES = -I$(SRC) \
           $(addprefix -I, $(shell find $(SRC) -type d)) \
           -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR)

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MINILIBX_FLAGS) $(LIBFT_FLAGS) $(FTPRINTF_FLAGS) $(GNL_FLAGS)

# FIX: @mkdir -p $(dir $@) ensures subfolders like obj/maps/ are created
$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(GNL_LIB):
	@make -C $(GNL_DIR)

$(FT_PRINTF_LIB):
	@make -C $(FTPRINTF_DIR)

clean:
	rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean
	@make -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@make -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re