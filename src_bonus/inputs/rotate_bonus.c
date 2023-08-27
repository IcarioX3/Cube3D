/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:19:16 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 16:40:51 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	rotate_right(t_game *game, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-speed)
		- game->player.dir_y * sin(-speed);
	game->player.dir_y = old_dir_x * sin(-speed)
		+ game->player.dir_y * cos(-speed);
	old_plane_x = game->camera.plane_x;
	game->camera.plane_x = game->camera.plane_x * cos(-speed)
		- game->camera.plane_y * sin(-speed);
	game->camera.plane_y = old_plane_x * sin(-speed)
		+ game->camera.plane_y * cos(-speed);
}

void	rotate_left(t_game *game, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(speed)
		- game->player.dir_y * sin(speed);
	game->player.dir_y = old_dir_x * sin(speed)
		+ game->player.dir_y * cos(speed);
	old_plane_x = game->camera.plane_x;
	game->camera.plane_x = game->camera.plane_x * cos(speed)
		- game->camera.plane_y * sin(speed);
	game->camera.plane_y = old_plane_x * sin(speed)
		+ game->camera.plane_y * cos(speed);
}
