/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:20:35 by icario            #+#    #+#             */
/*   Updated: 2023/08/24 11:18:34 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cube3D.h"

int	main(int ac, char **av)
{
	int		fd;
	t_vars	*vars;
	t_game	game;

	(void)game;
	if (ac != 2)
		return (write (2, "Error : Wrong input\n", 21), 1);	
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "error: can't open the file\n", 28), 1);
	if (check_args(av[1]) == 1)
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
	(vars)->ceiling_info = NULL;
    (vars)->floor_info = NULL;
	vars->file_texture = NULL;
	parsing(&vars);
	close(fd);

 	init(&game, vars);
	start(&game);
	return (0);
}
