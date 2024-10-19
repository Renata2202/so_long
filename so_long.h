/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:38:14 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/19 17:39:53 by rnunes-a         ###   ########.fr       */
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

// init_game.c
t_data *initialize_data(void);

#endif
