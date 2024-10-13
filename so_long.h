/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:38:14 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/13 15:34:22 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game {
    void *mlx;
    void *win;
    int moves;
    // outros componentes do jogo (mapa, jogador, etc.)
} t_game;

void init_game(t_game *game);
void handle_input(int keycode, t_game *game);
void render_map(t_game *game);
void game_loop(t_game *game);

#endif
