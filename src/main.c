/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franckgojard <franckgojard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:20:35 by icario            #+#    #+#             */
/*   Updated: 2023/07/17 17:36:23 by franckgojar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
			return (NULL);
		map = ft_strdup(mapgnl);
		if (map == NULL)
			return (NULL);
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


int	main(int ac, char **av)
{
	int		fd;
	t_vars	*vars;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mapline = get_map(fd);
	if (vars->mapline == NULL)
	{
		free(vars);
		close(fd);
		return (0);
	}
	vars->map = ft_split(vars->mapline, '\n');
	if (vars->map == NULL)
	{
		free(vars->mapline);
		free(vars);
		return (0);
	}
	int i = 0;
	while (vars->map[i])
	{
		printf("%s\n", vars->map[i]);
		i++;
	}
	close(fd);
	return (0);
}
