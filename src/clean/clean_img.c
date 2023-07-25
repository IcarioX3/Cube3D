/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:43:23 by icario            #+#    #+#             */
/*   Updated: 2023/07/24 15:32:00 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	clean_img(t_game *game)
{
	if (game->mlx.img)
	{
		mlx_destroy_image(game->mlx.ptr, game->mlx.img);
	}
}
