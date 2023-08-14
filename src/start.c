/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:47:01 by icario            #+#    #+#             */
/*   Updated: 2023/08/14 18:50:11 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	start(t_game *game)
{
	game->floor_color = GREEN_GRASS;
	game->ceiling_color = BLUE_SKY;
	create_floor_and_ceiling(game);
	raycaster(game);
	mlx_key_hook(game->mlx.win, inputs, game);
	mlx_hook(game->mlx.win, 17, 0, terminate, game);
	mlx_loop(game->mlx.ptr);
}
