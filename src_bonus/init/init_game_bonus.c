/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:03:24 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:04:09 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"
#include "parsing_bonus.h"

void	init_camera(t_game *game)
{
	if (game->vars->player == 'N')
	{
		game->camera.plane_x = 0;
		game->camera.plane_y = 0.66;
	}
	else if (game->vars->player == 'S')
	{
		game->camera.plane_x = 0;
		game->camera.plane_y = -0.66;
	}
	else if (game->vars->player == 'E')
	{
		game->camera.plane_y = 0;
		game->camera.plane_x = 0.66;
	}
	else if (game->vars->player == 'W')
	{
		game->camera.plane_y = 0;
		game->camera.plane_x = -0.66;
	}	
}

void	init_player(t_player *player, t_vars *vars)
{
	player->pos_x = vars->begin_x;
	player->pos_y = vars->begin_y;
	if (vars->player == 'N')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
	else if (vars->player == 'S')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (vars->player == 'E')
	{
		player->dir_y = 1;
		player->dir_x = 0;
	}
	else if (vars->player == 'W')
	{
		player->dir_y = -1;
		player->dir_x = 0;
	}
	vars->map[vars->begin_x][vars->begin_y] = '0';
}

void	init_game(t_game *game, t_vars *vars)
{
	init_camera(game);
	init_player(&game->player, vars);
}
