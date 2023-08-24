/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:30:05 by icario            #+#    #+#             */
/*   Updated: 2023/08/24 10:54:58 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	clean_parsing(t_game *game)
{
	int	a;
	
	a = 0;
	while (a < 4)
	{
		free(game->vars->file_texture[a]);
		a++;
	}
	free(game->vars->file_texture);
	free(game->vars->mapline);
	free_double_tab(game->vars->map);
	free_double_tab(game->vars->map_info);
	if (game->vars->floor_info)
		free(game->vars->floor_info);
	if (game->vars->ceiling_info)
		free(game->vars->ceiling_info);
	free(game->vars);
}
