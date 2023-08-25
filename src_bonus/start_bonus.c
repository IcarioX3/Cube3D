/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:56:44 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 18:57:38 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"
#include "parsing_bonus.h"

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
