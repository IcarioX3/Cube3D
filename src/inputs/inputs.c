/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:26 by antoine           #+#    #+#             */
/*   Updated: 2023/08/14 18:56:49 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	inputs(int key, t_game *game)
{
	if (key == 65307)
		terminate(game);
	//if w or up arrow is pressed
	else if (key == 119 || key == 65362)
	{
		//if the next position is not a wall
		if (game->map[(int)(game->player.pos_x + game->player.dir_x
				* MOVE_SPEED)][(int)game->player.pos_y] == 0)
			game->player.pos_x += game->player.dir_x * MOVE_SPEED;
		//if the next position is not a wall
		if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
				+ game->player.dir_y * MOVE_SPEED)] == 0)
			game->player.pos_y += game->player.dir_y * MOVE_SPEED;
	}
	//if s or down arrow is pressed
	else if (key == 115 || key == 65364)
	{
		//if the next position is not a wall
		if (game->map[(int)(game->player.pos_x - game->player.dir_x
				* MOVE_SPEED)][(int)game->player.pos_y] == 0)
			game->player.pos_x -= game->player.dir_x * MOVE_SPEED;
		//if the next position is not a wall
		if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
				- game->player.dir_y * MOVE_SPEED)] == 0)
			game->player.pos_y -= game->player.dir_y * MOVE_SPEED;
	}
	//if d or right arrow is pressed
/* 	if (key == 100 || key == 65363)
	{
		double	old_dir_x;
		double	old_plane_x;

		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-ROT_SPEED)
			- game->player.dir_y * sin(-ROT_SPEED);
		game->player.dir_y = old_dir_x * sin(-ROT_SPEED)
			+ game->player.dir_y * cos(-ROT_SPEED);
		old_plane_x = game->camera.plane_x;
		game->camera.plane_x = game->camera.plane_x * cos(-ROT_SPEED)
			- game->camera.plane_y * sin(-ROT_SPEED);
		game->camera.plane_y = old_plane_x * sin(-ROT_SPEED)
			+ game->camera.plane_y * cos(-ROT_SPEED);
	} */
	raycaster(game);
	return (0);
}
