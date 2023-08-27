/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:43:23 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 16:40:28 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_img(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img != NULL && &game->textures[i].img)
		{
			mlx_destroy_image(game->mlx.ptr, game->textures[i].img);
		}
		i++;
	}
	if (game->mlx.img)
	{
		mlx_destroy_image(game->mlx.ptr, game->mlx.img);
	}
}
