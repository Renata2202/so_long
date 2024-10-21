/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:38:14 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/21 15:47:31 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		exit;
	int		collectibles;
	int		collectibles_collected;
	int		moves;
}	t_map;

typedef struct s_textures
{
	void	*walls;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_textures;

typedef struct s_data
{
	void		*mlx;
	void		*win;
//	int			width;
//	int			height;
	t_textures	*textures;
	t_map		*map;
}	t_data;


// main.c


// init_game.c
t_data *initialize_data(void);

// handle_input.c
int check_extension(char *file);
int check_map_walls_and_chars(t_map *map_data);
int check_map_shape(t_map *map_data);

#endif
