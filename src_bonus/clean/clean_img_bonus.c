/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_img_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:58:31 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 18:58:54 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"

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
