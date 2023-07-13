/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:40:45 by icario            #+#    #+#             */
/*   Updated: 2023/07/13 14:46:13 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	init_mlx(t_game *game)
{
	game->mlx.ptr = mlx_init();
	if (!game->mlx.ptr)
		exit_msg("Error\nmlx_init() failed\n", game);
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, "cube3D");
	if (!game->mlx.win)
		exit_msg("Error\nmlx_new_window() failed\n", game);
}
