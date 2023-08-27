/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:52:03 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 17:48:25 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//draw a minimap at the bottom right of the screen

#include "cub3D_bonus.h"

//draw a square of size 5x5
static void	draw_square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(&game->mlx, x * 5 + i, y * 5 + j, color);
			j++;
		}
		i++;
	}
}

//draw the player on the minimap as a blue square using draw_square()
static void	draw_player(t_game *game)
{
	int	x;
	int	y;

	y = (int)game->player.pos_x;
	x = (int)game->player.pos_y;
	draw_square(game, x, y, 0xFF0000);
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->vars->map[y] != NULL && y < HEIGHT - 1)
	{
		x = 0;
		while (game->vars->map[y][x] != '\0' && x < WIDTH - 1)
		{
			if (game->vars->map[y][x] == '1')
				draw_square(game, x, y, 0x9370DB);
			else if (game->vars->map[y][x] == '0')
				draw_square(game, x, y, 0x000000);
			else if (game->vars->map[y][x] == '2'
				|| game->vars->map[y][x] == '3')
				draw_square(game, x, y, 0xFFFF00);
			x++;
		}
		y++;
	}
	draw_player(game);
}
