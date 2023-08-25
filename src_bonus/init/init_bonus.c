/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:09:34 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:10:06 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"
#include "parsing_bonus.h"

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
