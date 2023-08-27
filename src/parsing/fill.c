/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:04:04 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/27 18:58:52 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	fill2(int i, int j, char c, char **map)
{
	int		has_neighbor;

	has_neighbor = 0;
	if (c == '0' || c == 'S' || c == 'N' || c == 'E' || c == 'W')
	{
		if (i > 0 && map[i - 1][j] == ' ')
			has_neighbor = 1;
		if (map[i + 1] == NULL )
			has_neighbor = 1;
		else if (map[i + 1][j] == ' ')
			has_neighbor = 1;
		if (j > 0 && map[i][j - 1] == ' ')
			has_neighbor = 1;
		if (map[i][j + 1] == '\0' || map[i][j + 1] == ' ')
			has_neighbor = 1;
		if (has_neighbor == 1)
			return (write (2, "Error : the map must be closed\n", 32),
				1);
	}
	return (0);
}

int	fill(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (map == NULL)
		return (1);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			c = map[i][j];
			if (fill2(i, j, c, map) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
