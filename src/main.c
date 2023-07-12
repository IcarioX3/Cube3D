/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:20:35 by icario            #+#    #+#             */
/*   Updated: 2023/07/12 19:35:02 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	main(void)
{
	t_game	game;
	//void	*img;

	if (!(game.mlx.ptr = mlx_init()))
		exit_msg("Error\nmlx_init() failed\n");
 	if (!(game.mlx.win = mlx_new_window(game.mlx.ptr, WIDTH, HEIGHT, "cube3D")))
		exit_msg("Error\nmlx_new_window() failed\n");
	//img = mlx_new_image(game.mlx.ptr, WIDTH, HEIGHT);
	mlx_hook(game.mlx.win, 17, 0, terminate, &game);
	mlx_loop(game.mlx.ptr);
	return (0);
}
