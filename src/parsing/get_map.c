/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:59:01 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/28 16:45:08 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_map_line(char *map)
{
	int		i;

	i = 0;
	if (map == NULL)
		return (1);
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n' && map[i - 1] == '1'
			&& map[i + 1] != '\0')
			return (write(2, "error: map not valid\n", 21), 1);
		i++;
	}
	return (0);
}

char	*get_map(int fd)
{
	char	*mapgnl;
	char	*map;

	mapgnl = NULL;
	map = NULL;
	if (mapgnl == NULL)
	{
		mapgnl = get_next_line(fd);
		if (mapgnl == NULL)
			return (write(2, "error: empty file\n", 19), NULL);
		map = ft_strdup(mapgnl);
		if (map == NULL)
			return (free(mapgnl), NULL);
		free(mapgnl);
	}
	while (mapgnl != NULL)
	{
		mapgnl = get_next_line(fd);
		if (mapgnl != NULL)
			map = ft_strjoin(map, mapgnl);
		if (check_map_line(map) == 1)
			return (free(mapgnl), free(map), NULL);
		free(mapgnl);
	}
	return (map);
}
