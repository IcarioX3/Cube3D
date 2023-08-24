/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:28:55 by icario            #+#    #+#             */
/*   Updated: 2023/08/24 10:32:00 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

//Order of file_texture: NO, SO, EA, WE
void	init_tex_struct(t_game *game)
{
/* 	game->textures[0].filename = game->vars.file_texture[0];
	game->textures[1].filename = game->vars.file_texture[1];
	game->textures[2].filename = game->vars.file_texture[2];
	game->textures[3].filename = game->vars.file_texture[3]; */
	game->textures[0].filename = "textures/wall.xpm";
	game->textures[1].filename = "textures/wall.xpm";
	game->textures[2].filename = "textures/wall.xpm";
	game->textures[3].filename = "textures/wall.xpm"; 
}
