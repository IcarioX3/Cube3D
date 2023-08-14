/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:26 by antoine           #+#    #+#             */
/*   Updated: 2023/08/14 21:14:43 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	inputs(int key, t_game *game)
{
	if (key == 65307)
		terminate(game);
	//if w is pressed move forward
	if (key == 119)
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
	//if s is pressed move backward
	else if (key == 115)
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
	//if d is pressed move right
	else if (key == 100)
	{
		//if the next position is not a wall
		if (game->map[(int)(game->player.pos_x + game->player.dir_y
				* MOVE_SPEED)][(int)game->player.pos_y] == 0)
			game->player.pos_x += game->player.dir_y * MOVE_SPEED;
		//if the next position is not a wall
		if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
				- game->player.dir_x * MOVE_SPEED)] == 0)
			game->player.pos_y -= game->player.dir_x * MOVE_SPEED;
	}
	//if a is pressed move left
	else if (key == 97)
	{
		//if the next position is not a wall
		if (game->map[(int)(game->player.pos_x - game->player.dir_y
				* MOVE_SPEED)][(int)game->player.pos_y] == 0)
			game->player.pos_x -= game->player.dir_y * MOVE_SPEED;
		//if the next position is not a wall
		if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
				+ game->player.dir_x * MOVE_SPEED)] == 0)
			game->player.pos_y += game->player.dir_x * MOVE_SPEED;
	}
	//if left arrow is pressed
	if (key == 65361)
	{
		double	old_dir_x;
		double	old_plane_x;

		old_dir_x = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(ROT_SPEED)
			- game->player.dir_y * sin(ROT_SPEED);
		game->player.dir_y = old_dir_x * sin(ROT_SPEED)
			+ game->player.dir_y * cos(ROT_SPEED);
		old_plane_x = game->camera.plane_x;
		game->camera.plane_x = game->camera.plane_x * cos(ROT_SPEED)
			- game->camera.plane_y * sin(ROT_SPEED);
		game->camera.plane_y = old_plane_x * sin(ROT_SPEED)
			+ game->camera.plane_y * cos(ROT_SPEED);
	}
	//if right arrow is pressed
	if (key == 65363)
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
	}
	raycaster(game);
	return (0);
}
