/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablevin <ablevin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:07:48 by icario            #+#    #+#             */
/*   Updated: 2023/08/23 14:06:40 by ablevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#include "parsing.h"

void	init(t_game *game, t_vars *vars)
{
	init_game_struct(game);
	init_mlx_struct(&game->mlx);
	init_player_struct(&game->player);
	init_camera_struct(&game->camera);
	init_raycaster_struct(&game->raycaster);
	init_mlx(game);
	init_game(game, vars);
}
