/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:07:48 by icario            #+#    #+#             */
/*   Updated: 2023/08/23 18:04:42 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init(t_game *game)
{
	init_game_struct(game);
	init_mlx_struct(&game->mlx);
	init_player_struct(&game->player);
	init_camera_struct(&game->camera);
	init_raycaster_struct(&game->raycaster);
	init_tex_struct(game);
	init_mlx(game);
	init_game(game);
	init_textures(game);
}
