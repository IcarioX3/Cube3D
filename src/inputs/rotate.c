/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:50:25 by antoine           #+#    #+#             */
/*   Updated: 2023/08/14 22:00:45 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	rotate_right(t_game *game)
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

void	rotate_left(t_game *game)
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

void	rotate(t_game *game, int key)
{
	if (key == RIGHT_ARROW)
		rotate_right(game);
	else if (key == LEFT_ARROW)
		rotate_left(game);
}
