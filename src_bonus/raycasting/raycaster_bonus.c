/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:54:15 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 20:28:30 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"

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

void	dda(t_game *game)
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
		if (game->vars->map[game->player.map_x][game->player.map_y] == '1')
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
	int	x;

	x = 0;
	create_floor_and_ceiling(game);
	while (x < WIDTH)
	{
		init_value(game, x);
		init_x_wall_detection(game);
		init_y_wall_detection(game);
		dda(game);
		draw_pixels(game, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
}
