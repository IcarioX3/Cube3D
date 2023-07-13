/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:47:01 by icario            #+#    #+#             */
/*   Updated: 2023/07/13 14:56:28 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	start(t_game *game)
{
	init_mlx(game);
	mlx_hook(game->mlx.win, 17, 0, terminate, game);
	mlx_loop(game->mlx.ptr);
}
