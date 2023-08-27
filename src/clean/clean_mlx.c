/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:10:28 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 16:40:28 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_mlx(t_game *game)
{
	if (game->mlx.ptr)
	{
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
}
