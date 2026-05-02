# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/01 23:05:09 by pang              #+#    #+#              #
#    Updated: 2026/05/01 23:05:09 by pang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wextra -Werror -Wall

NAME    = cub3D

LIBFT_DIR    = ./libft/libft01
FTPRINTF_DIR = ./libft/ft_printf
GNL_DIR      = ./libft/gnl
MLX_DIR      = ./mlx
SRC          = src
OBJ          = obj

LIBFT_LIB     = $(LIBFT_DIR)/libft.a
GNL_LIB       = $(GNL_DIR)/libftgnl.a
FT_PRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a
MLX_LIB       = $(MLX_DIR)/libmlx.a

MINILIBX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT_FLAGS    = -L$(LIBFT_DIR) -lft
FTPRINTF_FLAGS = -L$(FTPRINTF_DIR) -lftprintf
GNL_FLAGS      = -L$(GNL_DIR) -lftgnl

SRCS = $(shell find $(SRC) -name "*.c")
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

INCLUDES = -I$(SRC) \
           $(addprefix -I, $(shell find $(SRC) -type d)) \
		   -I$(MLX_DIR) \
           -I$(LIBFT_DIR) -I$(FTPRINTF_DIR) -I$(GNL_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MINILIBX_FLAGS) $(LIBFT_FLAGS) $(FTPRINTF_FLAGS) $(GNL_FLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(GNL_LIB):
	@make -C $(GNL_DIR)

$(FT_PRINTF_LIB):
	@make -C $(FTPRINTF_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ)
	@make -C $(MLX_DIR) clean
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