/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:46:27 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:46:49 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	parsing(t_vars **vars)
{
	if (check_file(vars, (*vars)->map) == 1)
		return (1);
	if (split_file_map(vars) == 1)
		return (1);
	if (check_map(vars, (*vars)->map, 0) == 1)
		return (1);
	if (fill((*vars)->map) == 1)
		return (1);
	if (check_texture(vars) == 1)
		return (1);
	return (0);
}

int	init_parsing(t_vars **vars, char **av, int fd)
{	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "error: can't open the file\n", 28), 1);
	*vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	(*vars)->mapline = get_map(fd);
	if ((*vars)->mapline == NULL)
	{
		close(fd);
		return (free(*vars), 1);
	}
	(*vars)->map = ft_split((*vars)->mapline, '\n');
	if ((*vars)->map == NULL)
	{
		free((*vars)->mapline);
		return (free(*vars), 1);
	}
	(*vars)->ceiling_info = NULL;
	(*vars)->floor_info = NULL;
	(*vars)->file_texture = NULL;
	(*vars)->file_texture = malloc(4 * sizeof(char *));
	close(fd);
	return (0);
}
