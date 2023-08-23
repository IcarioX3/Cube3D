/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:28:55 by icario            #+#    #+#             */
/*   Updated: 2023/08/23 18:02:04 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_tex_struct(t_game *game)
{
	game->textures[0].filename = "textures/wall.xpm";
	game->textures[1].filename = "textures/wall.xpm";
	game->textures[2].filename = "textures/wall.xpm";
	game->textures[3].filename = "textures/wall.xpm";
}
