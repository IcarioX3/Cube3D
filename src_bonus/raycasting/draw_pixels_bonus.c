/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablevin <ablevin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:52:44 by icario            #+#    #+#             */
/*   Updated: 2023/08/28 16:47:50 by ablevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	tex_pix_get(t_game *game, int index_tex, int x, int y)
{
	char	*red;
	char	*green;
	char	*blue;
	int		color;

	red = game->textures[index_tex].addr + (y
			* game->textures[index_tex].line_length + x
			* (game->textures[index_tex].bits_per_pixel / 8));
	green = red + 1;
	blue = green + 1;
	color = (256 * 256 * *red + 256 * *green + *blue);
	if (color == 3418972)
		color -= game->shade * 1000;
	if (color == 1708858)
		color -= game->shade * 1000;
	if (color == 2758958)
		color -= game->shade * 1000;
	return (color);
}	

void	put_tex(t_game *game, int x, int y)
{
	if (game->raycaster.side == 0 && game->raycaster.ray_dir_x > 0)
		my_mlx_pixel_put(&game->mlx, x, y, tex_pix_get(game, 0,
				game->raycaster.tex_x, game->raycaster.tex_y));
	else if (game->raycaster.side == 0 && game->raycaster.ray_dir_x < 0)
		my_mlx_pixel_put(&game->mlx, x, y, tex_pix_get(game, 1,
				game->raycaster.tex_x, game->raycaster.tex_y));
	else if (game->raycaster.side == 1 && game->raycaster.ray_dir_y > 0)
		my_mlx_pixel_put(&game->mlx, x, y, tex_pix_get(game, 2,
				game->raycaster.tex_x, game->raycaster.tex_y));
	else if (game->raycaster.side == 1 && game->raycaster.ray_dir_y < 0)
		my_mlx_pixel_put(&game->mlx, x, y, tex_pix_get(game, 3,
				game->raycaster.tex_x, game->raycaster.tex_y));
}

void	put_pixel(t_game *game, int x, int draw_start, int draw_end)
{
	int	y;

	y = draw_start;
	if (game->raycaster.side == 0)
		game->raycaster.wall_x = game->player.pos_y
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir_y;
	else
		game->raycaster.wall_x = game->player.pos_x
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir_x;
	game->raycaster.wall_x -= floor(game->raycaster.wall_x);
	game->raycaster.tex_x = (int)(game->raycaster.wall_x * (double)TEX_WIDTH);
	if (game->raycaster.side == 0 && game->raycaster.ray_dir_x > 0)
		game->raycaster.tex_x = TEX_WIDTH - game->raycaster.tex_x - 1;
	if (game->raycaster.side == 1 && game->raycaster.ray_dir_y < 0)
		game->raycaster.tex_x = TEX_WIDTH - game->raycaster.tex_x - 1;
	while (y < draw_end)
	{
		game->raycaster.tex_y = (int)game->raycaster.tex_pos & (TEX_WIDTH - 1);
		game->raycaster.tex_pos += game->raycaster.step;
		put_tex(game, x, y);
		y++;
	}
}

void	draw_pixels(t_game *game, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HEIGHT / game->raycaster.perp_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT;
	game->raycaster.step = 1.0 * TEX_WIDTH / line_height;
	game->raycaster.tex_pos = (draw_start - HEIGHT / 2 + line_height / 2)
		* game->raycaster.step;
	put_pixel(game, x, draw_start, draw_end);
}
