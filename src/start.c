/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:47:01 by icario            #+#    #+#             */
/*   Updated: 2023/07/23 13:03:47 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	create_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->mlx, x, y, game->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->mlx, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}

void	start(t_game *game)
{
	init(game);
	game->floor_color = GREEN_GRASS;
	game->ceiling_color = BLUE_SKY;
	create_floor_and_ceiling(game);
	raycaster(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	mlx_hook(game->mlx.win, 17, 0, terminate, game);
	mlx_loop(game->mlx.ptr);
}
