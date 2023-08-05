/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:42:36 by antoine           #+#    #+#             */
/*   Updated: 2023/08/05 18:51:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

/* void	raycaster(t_game *game)
{
		int	map[10][10] = {
    	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   		{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    	{1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
		//counter for x (WIDTH) and y (HEIGHT) pixels
	int	x;
	int	y;
	//height of line on screen
	int lineHeight;
	//lowest and highest pixel to fill in current stripe
	int drawStart;
	int	drawEnd;
			
	x = 0;

	while (x < WIDTH)
	{
		game->camera.camera_x = 2 * x / (double)WIDTH - 1;
		game->raycaster.ray_dir_x = game->player.dir_x + game->camera.plane_x
			* game->camera.camera_x;
		game->raycaster.ray_dir_y = game->player.dir_y + game->camera.plane_y
			* game->camera.camera_x;
		game->player.map_x = (int)game->player.pos_x;
		game->player.map_y = (int)game->player.pos_y;
		game->raycaster.delta_dist_x = fabs(1 / game->raycaster.ray_dir_x);
		game->raycaster.delta_dist_y = fabs(1 / game->raycaster.ray_dir_y);
		game->raycaster.hit = 0;
		
		if (game->raycaster.ray_dir_x < 0)
		{
			game->raycaster.step_x = -1;
			game->raycaster.side_dist_x = (game->player.pos_x - game->player.map_x)
				* game->raycaster.delta_dist_x;
		}
		else
		{
			game->raycaster.step_x = 1;
			game->raycaster.side_dist_x = (game->player.map_x + 1.0 - game->player.pos_x)
				* game->raycaster.delta_dist_x;
		}
		if (game->raycaster.ray_dir_y < 0)
		{
			game->raycaster.step_y = -1;
			game->raycaster.side_dist_y = (game->player.pos_y - game->player.map_y)
				* game->raycaster.delta_dist_y;
		}
		else
		{
			game->raycaster.step_y = 1;
			game->raycaster.side_dist_y = (game->player.map_y + 1.0 - game->player.pos_y)
				* game->raycaster.delta_dist_y;
		}

		while (game->raycaster.hit == 0)
		{
			if (game->raycaster.side_dist_x < game->raycaster.side_dist_y)
			{
				game->raycaster.side_dist_x += game->raycaster.delta_dist_x;
				game->player.map_x += game->raycaster.step_x;
				game->raycaster.side = 0;
			}
			else
			{
				game->raycaster.side_dist_y += game->raycaster.delta_dist_y;
				game->player.map_y += game->raycaster.step_y;
				game->raycaster.side = 1;
			}
			if (map[game->player.map_x][game->player.map_y] > 0)
				game->raycaster.hit = 1;
		}

		if (game->raycaster.side == 0)
			game->raycaster.perp_wall_dist = game->raycaster.side_dist_x
				- game->raycaster.delta_dist_x;
		else
			game->raycaster.perp_wall_dist = game->raycaster.side_dist_y
				- game->raycaster.delta_dist_y;

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
		x++;
	}
} */

void	init_value(t_game *game, int x)
{
	game->camera.camera_x = 2 * x / (double)WIDTH - 1;
	game->raycaster.ray_dir_x = game->player.dir_x + game->camera.plane_x
		* game->camera.camera_x;
	game->raycaster.ray_dir_y = game->player.dir_y + game->camera.plane_y
		* game->camera.camera_x;
	game->player.map_x = (int)game->player.pos_x;
	game->player.map_y = (int)game->player.pos_y;
	game->raycaster.delta_dist_x = fabs(1 / game->raycaster.ray_dir_x);
	game->raycaster.delta_dist_y = fabs(1 / game->raycaster.ray_dir_y);
	game->raycaster.hit = 0;
}

void	init_x_wall_detection(t_game *game)
{	
	t_raycaster	*raycaster;
	t_player	*player;

	raycaster = &game->raycaster;
	player = &game->player;
	if (raycaster->ray_dir_x < 0)
	{
		raycaster->step_x = -1;
		raycaster->side_dist_x = (player->pos_x - player->map_x)
			* raycaster->delta_dist_x;
	}
	else
	{
		raycaster->step_x = 1;
		raycaster->side_dist_x = (player->map_x + 1.0 - player->pos_x)
			* raycaster->delta_dist_x;
	}
}

void	init_y_wall_detection(t_game *game)
{
	t_raycaster	*raycaster;
	t_player	*player;

	raycaster = &game->raycaster;
	player = &game->player;
	if (raycaster->ray_dir_y < 0)
	{
		raycaster->step_y = -1;
		raycaster->side_dist_y = (player->pos_y - player->map_y)
			* raycaster->delta_dist_y;
	}
	else
	{
		raycaster->step_y = 1;
		raycaster->side_dist_y = (player->map_y + 1.0 - player->pos_y)
			* raycaster->delta_dist_y;
	}
}

void	dda(t_game *game, int map[10][10])
{
	while (game->raycaster.hit == 0)
	{
		if (game->raycaster.side_dist_x < game->raycaster.side_dist_y)
		{
			game->raycaster.side_dist_x += game->raycaster.delta_dist_x;
			game->player.map_x += game->raycaster.step_x;
			game->raycaster.side = 0;
		}
		else
		{
			game->raycaster.side_dist_y += game->raycaster.delta_dist_y;
			game->player.map_y += game->raycaster.step_y;
			game->raycaster.side = 1;
		}
		if (map[game->player.map_x][game->player.map_y] > 0)
			game->raycaster.hit = 1;
	}
	if (game->raycaster.side == 0)
		game->raycaster.perp_wall_dist = game->raycaster.side_dist_x
			- game->raycaster.delta_dist_x;
	else
		game->raycaster.perp_wall_dist = game->raycaster.side_dist_y
			- game->raycaster.delta_dist_y;
}

void	raycaster(t_game *game)
{
	int	map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   		{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    	{1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_value(game, x);
		init_x_wall_detection(game);
		init_y_wall_detection(game);
		dda(game, map);
		draw_pixels(game, x);
		x++;
	}
}
