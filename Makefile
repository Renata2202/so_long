# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 15:33:15 by rnunes-a          #+#    #+#              #
#    Updated: 2024/10/19 14:56:47 by rnunes-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Detecta o sistema operacional
UNAME := $(shell uname)

# Configurações específicas para Linux ou MacOS
ifeq ($(UNAME), Linux)
    MLX_DIR = ./minilibx-linux
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext
    INCLUDES = -I$(MLX_DIR)
else
    MLX_DIR = ./minilibx-mac
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
    INCLUDES = -I$(MLX_DIR) -I/opt/X11/include
endif


SRCS = main.c src/init_game.c src/handle_input.c \
src/render_map.c src/game_loop.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft/
	$(MAKE) -C ft_printf/
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libft/
	$(MAKE) clean -C ft_printf/

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/
	$(MAKE) fclean -C ft_printf/

re: fclean all

.PHONY: all clean fclean re
.SILENT:
