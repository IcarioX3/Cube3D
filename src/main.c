/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franck <franck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:20:35 by icario            #+#    #+#             */
/*   Updated: 2023/08/11 01:59:31 by franck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int ac, char **av)
{
	int		fd;
	t_vars	*vars;

	if (ac != 2)
		return (write (2, "Error : Wrong input\n", 21), 1);	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1); //perror
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
	(vars)->ceiling_info = NULL;
    (vars)->floor_info = NULL;
	parsing(&vars, av);
	// int i = 0;
	// while (vars->map[i])
	// {
	// 	printf("%s\n", vars->map[i]);
	// 	i++;
	// }
	//printf("pos x : %d\npos y : %d\n", vars->begin_x, vars->begin_y);
	free(vars->mapline);
	free_double_tab(vars->map);
	free_double_tab(vars->map_info);
	if (vars->floor_info)
		free(vars->floor_info);
	if (vars->ceiling_info)
		free(vars->ceiling_info);
	free(vars);
	close(fd);
	return (0);
}
