/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:35:25 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/21 17:18:51 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int main(int argc, char **argv)
{
	t_data *data;

	data = initialize_data();
	if (!data)
		return (1);

	// Supondo que o map_data já foi preenchido com o mapa e suas dimensões
	if (check_map_shape(data->map) || check_map_walls_and_chars(data->map))
	{
		ft_printf("Erro: Mapa inválido.\n");
		free(data->textures);
		free(data->map);
		free(data);
		return (1);
	}

	// Código para o loop principal do jogo aqui (game loop, etc.)

	free(data->textures);
	free(data->map);
	free(data);
	return (0);
}


// int	close_window(void *mlx, void *win)
// {
// 	mlx_destroy_window(mlx, win);
// 	mlx_destroy_display(mlx);
// 	exit(0);
// }

// int	main(void)

// {
// 	void	*mlx;
// 	void	*win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 800, 800, "so_long");
// 	mlx_hook(win, 17, 1L << 17, close_window, mlx);
// 	mlx_loop(mlx);
// }

/*
so_long/
│   Makefile
│   main.c            # Arquivo principal do jogo
│   so_long.h            # Header com protótipos e definições
│   libft/               # Biblioteca Libft (se já implementada)
│   ft_printf/           # ft_printf ou sua implementação equivalente
│
└─── src/                # Código-fonte separado por funcionalidades
	│   init_game.c      # Inicialização do jogo
	│   handle_input.c   # VERIFICACAO DOS MAPAS
	│   render_map.c     # Renderização do mapa
	│   game_loop.c      # Lógica principal do jogo E Manipulação de teclas (movimentos)
	└─── assets/         # Recursos gráficos (texturas)


*/
