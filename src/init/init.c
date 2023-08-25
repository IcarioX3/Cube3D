/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:07:48 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 14:50:49 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#include "parsing.h"

void	init(t_game *game, t_vars *vars)
{
	game->vars = vars;
	init_game_struct(game);
	init_mlx_struct(&game->mlx);
	init_player_struct(&game->player);
	init_camera_struct(&game->camera);
	init_raycaster_struct(&game->raycaster);
	init_tex_struct(game);
	init_mlx(game);
	init_game(game, vars);
	init_textures(game);
}
