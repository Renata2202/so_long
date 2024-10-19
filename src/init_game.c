/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:39:55 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/19 17:39:06 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data *initialize_data(void)
{
	t_data *data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		ft_printf("Erro ao alocar memória para data.\n");
		return NULL;
	}
	data->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!data->textures)
	{
		free(data);
		ft_printf("Erro ao alocar memória para textures.\n");
		return NULL;
	}
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
	{
		free(data->textures);
		free(data);
		ft_printf("Erro ao alocar memória para map.\n");
		return NULL;
	}
	return data;
}


// void init_game(t_game *game)
// {
//     game->mlx = mlx_init();
//     game->win = mlx_new_window(game->mlx, 640, 480, "So Long");
//     game->moves = 0;
//     // carregar o mapa e outros componentes
// }

