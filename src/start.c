/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:47:01 by icario            #+#    #+#             */
/*   Updated: 2023/08/23 19:14:00 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"
#include "parsing.h"

void	start(t_game *game)
{
	game->floor_color = GREEN_GRASS;
	game->ceiling_color = BLUE_SKY;
	create_floor_and_ceiling(game);
	raycaster(game);
	mlx_hook(game->mlx.win, 2, 1L << 0, inputs, game);
	mlx_hook(game->mlx.win, 17, 0, terminate, game);
	mlx_loop(game->mlx.ptr);
}
