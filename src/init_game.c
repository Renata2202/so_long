/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:39:55 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/19 16:18:00 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, 640, 480, "So Long");
    game->moves = 0;
    // carregar o mapa e outros componentes
}

