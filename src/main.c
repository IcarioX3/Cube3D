/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:20:35 by icario            #+#    #+#             */
/*   Updated: 2023/07/13 14:31:23 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_game	game;

	init(&game);
	if (!(game.mlx.ptr = mlx_init()))
		exit_msg("Error\nmlx_init() failed\n", &game);
 	if (!(game.mlx.win = mlx_new_window(game.mlx.ptr, WIDTH, HEIGHT, "cube3D")))
		exit_msg("Error\nmlx_new_window() failed\n", &game);
	mlx_hook(game.mlx.win, 17, 0, terminate, &game);
	mlx_loop(game.mlx.ptr);
	return (0);
}
