/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:39:38 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/21 16:56:36 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *file)
{
	char	*ber;
	char	*file_extension;

	ber = ".ber";
	if (ft_strlen (file) < 4)
		return (1);
	file_extension = file + ft_strlen(file) - 4;
	return (ft_strncmp(file_extension, ber, 4));
}

int	check_map_walls_and_chars(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->cols) // Verifica a primeira e última linha
		if (map_data->map[0][i] != '1' ||
			map_data->map[map_data->rows - 1][i++] != '1')
			return (1); // Primeira ou última linha sem paredes
	i = 1;
	while (i < map_data->rows - 1) // Verifica colunas e caracteres nas linhas intermediárias
	{
		if (map_data->map[i][0] != '1' ||
			map_data->map[i][map_data->cols - 1] != '1')
			return (1); // Primeira ou última coluna sem paredes
		j = 0;
		while (j < map_data->cols)
			if (map_data->map[i][j] != '1' && map_data->map[i][j] != '0' &&
				map_data->map[i][j] != 'C' && map_data->map[i][j] != 'P' &&
				map_data->map[i][j++] != 'E')
				return (1); // Caractere inválido encontrado
		i++;
	}
	return (0); // Todas as paredes e caracteres estão corretos
}

int	check_map_shape(t_map *map_data)
{
	int	row;
	int	first_row_length;

	row = 0;
	first_row_length = map_data->cols; // número de colunas da primeira linha
	while (row < map_data->rows)
	{
		if (first_row_length != map_data->cols)
			return (1); // Mapa não é retangular ou quadrado
		row++;
	}
	return (0); // Mapa é válido (quadrado ou retangular)
}

void	count_map_elements(t_map *map_data, int *player, int *exit, int *cltb)
{
	int i;
	int j;

	i = 0;
	while (i < map_data->rows)
	{
		j = 0;
		while (j < map_data->cols)
		{
			if (map_data->map[i][j] == 'P')
				(*player)++;
			else if (map_data->map[i][j] == 'E')
				(*exit)++;
			else if (map_data->map[i][j] == 'C')
				(*cltb)++;
			j++;
		}
		i++;
	}
}

int	check_map_elements(t_map *map_data)
{
	int	players;
	int	exits;
	int collectibles;

	players = 0;
	exits = 0;
	collectibles = 0;
	count_map_elements(map_data, &players, &exits, &collectibles);
	if (players != 1 || exits != 1 || collectibles < 1)
		return (1); // Erro se não houver 1 jogador, 1 saída ou nenhum coletável
	return (0);
}
