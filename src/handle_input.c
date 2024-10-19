/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:39:38 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/19 18:43:28 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_extension(char *file)
{
    char *ber = ".ber";
    char *file_extension;

     if (ft_strlen(file) < 4)
        return (1);

    file_extension = file + ft_strlen(file) - 4;
    return (ft_strncmp(file_extension, ber, 4));
}

int check_first_last_line(char *line)
{
    if (*line == '\0')
        return 0;
    if (*line != '1')
        return 1;
    return check_first_last_line(line + 1);
}

int check_wall_columns(char **map, int row, int total_rows)
{
    if (row >= total_rows - 1) // Condição de parada para as linhas intermediárias
        return 0; // Retorna 0 se todas as verificações forem bem-sucedidas

    // Verifica as colunas da linha atual
    if (map[row][0] != '1' || map[row][strlen(map[row]) - 1] != '1')
        return 1; // Retorna 1 se as colunas não forem '1's

    return check_wall_columns(map, row + 1, total_rows); // Chama a função recursivamente para a próxima linha
}

int check_map_walls(char **map, int rows)
{
    if (rows < 3)
        return 1; // Retorna 1 se o mapa não tiver paredes suficientes

    // Verifica a primeira linha
    if (check_first_last_line(map[0]) != 0)
        return 1; // Retorna 1 se a primeira linha não estiver correta

    // Verifica a última linha
    if (check_first_last_line(map[rows - 1]) != 0)
        return 1; // Retorna 1 se a última linha não estiver correta

    // Verifica as colunas da primeira e última linha para as linhas intermediárias
    if (check_wall_columns(map, 1, rows) != 0)
        return 1; // Retorna 1 se as colunas das linhas intermediárias não estiverem corretas

    return 0; // Retorna 0 se todas as verificações forem bem-sucedidas
}

// int	check_wall(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] && line[i] != '\n')
// 	{
// 		if (line[i] != '1')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	check_map_content(char *line, t_map *map, int n_line)
{
	int	i;

	i = 0;
	if (line[0] != '1')
		return (1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1')
			add_wall(n_line, i, map);
		else if (line[i] == 'P' && map->player_x < 1)
			add_player(n_line, i, map);
		else if (line[i] == 'C')
			add_collectible(n_line, i, map);
		else if (line[i] == 'E' && map->exit < 1)
			add_exit(n_line, i, map);
		else if (line[i] == '0')
			add_floor(n_line, i, map);
		else
			return (1);
		i++;
	}
	if (line[i - 1] != '1')
		return (1);
	return (0);
}

int	check_reachable(t_data *data)
{
	int		x;
	int		y;
	char	**temp_map;

	y = 0;
	x = 0;
	temp_map = copy_map(data->map->map, data->map->rows);
	if (!temp_map)
		return (1);
	if (check_reachable_aux(data, temp_map, x, y))
		return (1);
	return (0);
}

int	check_reachable_aux(t_data *data, char **temp_map, int x, int y)
{
	while (temp_map[y])
	{
		x = 0;
		while (temp_map[y][x])
		{
			if (temp_map[y][x] == 'E' || temp_map[y][x] == 'C')
			{
				if (!is_acessible(data, temp_map, x, y))
					return (free_array(temp_map), 1);
				free_array(temp_map);
				temp_map = copy_map(data->map->map, data->map->rows);
			}
			x++;
		}
		y++;
	}
	free_array(temp_map);
	return (0);
}
