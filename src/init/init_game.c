/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:26:52 by antoine           #+#    #+#             */
/*   Updated: 2023/08/27 18:12:36 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

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
	player->pos_x = vars->begin_x + 0.5;
	player->pos_y = vars->begin_y + 0.5;
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
