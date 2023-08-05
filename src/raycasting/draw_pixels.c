/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:46:06 by antoine           #+#    #+#             */
/*   Updated: 2023/08/05 18:50:25 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	draw_pixels(t_game *game, int x)
{
	int	y;
	int	lineHeight;
	int	drawStart;
	int	drawEnd;

	lineHeight = (int)(HEIGHT / game->raycaster.perp_wall_dist);
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	y = drawStart;
	while (y < drawEnd)
	{
		if (game->raycaster.side == 1)
			my_mlx_pixel_put(&game->mlx, x, y, 0xFF0000);
		else
			my_mlx_pixel_put(&game->mlx, x, y, 0xBB0000);
		y++;
	}
}
