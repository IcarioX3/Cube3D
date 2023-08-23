/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:14:03 by icario            #+#    #+#             */
/*   Updated: 2023/08/23 18:08:12 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_textures(t_game *game)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx.ptr,
				game->textures[i].filename, &game->textures[i].bits_per_pixel,
				&game->textures[i].line_length);
		game->textures[i].addr = mlx_get_data_addr(game->textures[i].img,
				&game->textures[i].bits_per_pixel, &game->textures[i].line_length,
				&game->textures[i].endian);
		i++;
	}
}
