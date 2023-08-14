/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:26:52 by antoine           #+#    #+#             */
/*   Updated: 2023/08/14 21:30:23 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

//Plane x and plane y are the camera plane coordinates
void	init_camera(t_camera *camera)
{
	camera->plane_x = CAMERA_PLANE_X;
	camera->plane_y = CAMERA_PLANE_Y;
}

void	init_player(t_player *player)
{
	player->pos_x = 3;
	player->pos_y = 3;
	player->dir_x = -1;
	player->dir_y = 0;
}

void	init_game(t_game *game)
{
	init_camera(&game->camera);
	init_player(&game->player);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || i == 9 || j == 0 || j == 9)
				game->map[i][j] = 1;
			else
				game->map[i][j] = 0;
		}
	}
	game->map[5][5] = 1;
}
