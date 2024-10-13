# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 15:33:15 by rnunes-a          #+#    #+#              #
#    Updated: 2024/10/13 16:09:45 by rnunes-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = ./minilibx-linux/libmlx.a
MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext
SRCS = main.c src/init_game.c src/handle_input.c \
src/render_map.c src/game_loop.c
{
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	exit(0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 800, "so_long");
	mlx_hook(win, 17, 1L << 17, close_window, mlx);
	mlx_loop(mlx);
}src/game_loop.c
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
