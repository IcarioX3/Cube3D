/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:26:52 by antoine           #+#    #+#             */
/*   Updated: 2023/07/23 11:02:11 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

//Plane x and plane y are the camera plane coordinates
void	init_camera(t_camera *camera)
{
	camera->plane_x = CAMERA_PLANE_X;
	camera->plane_y = CAMERA_PLANE_Y;
}

/*Pos x and pos y are the position of the player in the map
Dir x and dir y are the direction of the player
Map x and map y are the position of the player in the map*/
void	init_player(t_player *player)
{
	player->pos_x = 4;
	player->pos_y = 4;
	player->dir_x = 1;
	player->dir_y = 1;
}

void	init_game(t_game *game)
{
	init_camera(&game->camera);
	init_player(&game->player);
}
