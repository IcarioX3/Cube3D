/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:52:48 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/22 13:59:47 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_map_char(int i, int j, char **map)
{
	if (map[i][j] != '0' && map[i][j] != '1'
	&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
	&& map[i][j] != 'W' && map[i][j] != ' ')
		return (write (2, "Error : Wrong char in map\n", 26), 1);
	return (0);
}

int	check_map(t_vars **vars, char **map, int nb_player)
{
	int	i;
	int	j;

	i = -1;
	nb_player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (check_map_char(i, j, map) == 1)
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				(*vars)->begin_x = i;
				(*vars)->begin_y = j;
				(*vars)->player = map[i][j];
				nb_player++;
			}
		}
	}
	if (nb_player == 0 || nb_player > 1)
		return (write (2, "Error : more or less than 1 player\n", 36), 1);
	return (0);
}
