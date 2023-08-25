/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:59:27 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 18:59:46 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"

void	clean_mlx(t_game *game)
{
	if (game->mlx.ptr)
	{
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
}
