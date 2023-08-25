/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:28:55 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 17:49:46 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

//Order of file_texture: NO, SO, EA, WE
void	init_tex_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->textures[i].filename = game->vars->file_texture[i];
		game->textures[i].img = NULL;
		game->textures[i].addr = NULL;
		game->textures[i].bits_per_pixel = 0;
		game->textures[i].line_length = 0;
		game->textures[i].endian = 0;
		i++;
	}
}
