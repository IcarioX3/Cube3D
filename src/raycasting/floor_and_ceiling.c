/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:49:06 by antoine           #+#    #+#             */
/*   Updated: 2023/08/24 10:13:23 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	rgb_to_int(int rgb[3])
{
	int	color;

	color = 0;
	color += rgb[0] * 256 * 256;
	color += rgb[1] * 256;
	color += rgb[2];
	return (color);
}

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
			my_mlx_pixel_put(&game->mlx, x, y, rgb_to_int(game->vars.ceiling));
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->mlx, x, y, rgb_to_int(game->vars.floor));
			x++;
		}
		y++;
	}
}
