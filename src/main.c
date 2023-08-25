/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:20:35 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 17:51:51 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cube3D.h"

int	main(int ac, char **av)
{
	t_vars	*vars;
	t_game	game;

	(void)game;
	if (ac != 2)
		return (write(2, "Error : Wrong input\n", 21), 1);
	if (check_args(av[1]) == 1)
		return (1);
	if (init_parsing(&vars, av, 0) == 1)
		return (1);
	if (parsing(&vars) == 1)
	{
		clean_parsing1(&vars);
		return (1);
	}
	init(&game, vars);
	start(&game);
	return (0);
}
