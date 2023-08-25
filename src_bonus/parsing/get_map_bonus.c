/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:45:51 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:46:14 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

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
		free(mapgnl);
	}
	return (map);
}
