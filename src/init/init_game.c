/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:26:52 by antoine           #+#    #+#             */
/*   Updated: 2023/08/23 19:25:18 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#include "parsing.h"

//Plane x and plane y are the camera plane coordinates
void	init_camera(t_camera *camera)
{
	camera->plane_x = CAMERA_PLANE_X;
	camera->plane_y = CAMERA_PLANE_Y;
}

void	init_player(t_player *player, t_vars *vars)
{
	player->pos_x = vars->begin_x;
	player->pos_y = vars->begin_y;
	player->dir_x = -1;
	player->dir_y = 0;
}

void	init_game(t_game *game, t_vars *vars)
{
	game->vars = *vars;
	init_camera(&game->camera);
	init_player(&game->player, vars);
}
