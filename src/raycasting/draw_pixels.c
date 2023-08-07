/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:46:06 by antoine           #+#    #+#             */
/*   Updated: 2023/08/07 12:45:02 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	draw_pixels(t_game *game, int x)
{
	int	y;
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HEIGHT / game->raycaster.perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	y = draw_start;
	while (y < draw_end)
	{
		if (game->raycaster.side == 1)
			my_mlx_pixel_put(&game->mlx, x, y, 0xFF0000);
		else
			my_mlx_pixel_put(&game->mlx, x, y, 0xBB0000);
		y++;
	}
}
