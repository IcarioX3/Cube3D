/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:04:21 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:04:43 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"

void	init_mlx(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		exit_msg("Error\nmlx_init() failed\n", game);
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, TITLE);
	if (!game->mlx.win)
		exit_msg("Error\nmlx_new_window() failed\n", game);
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIDTH, HEIGHT);
	if (!game->mlx.img)
		exit_msg("Error\nmlx_new_image() failed\n", game);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bits_per_pixel,
			&game->mlx.line_length, &game->mlx.endian);
}
