/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:30:05 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 17:49:10 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	clean_parsing(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(game->vars->file_texture[i]);
		i++;
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

void	clean_parsing1(t_vars **vars)
{
	int	i;

	i = 0;
	if ((*vars)->file_texture)
	{
		while (i < 4)
		{
			free((*vars)->file_texture[i]);
			i++;
		}
	}
	free((*vars)->file_texture);
	if ((*vars)->mapline)
		free((*vars)->mapline);
	if ((*vars)->map)
		free_double_tab((*vars)->map);
	if ((*vars)->map_info)
		free_double_tab((*vars)->map_info);
	if ((*vars)->floor_info)
		free((*vars)->floor_info);
	if ((*vars)->ceiling_info)
		free((*vars)->ceiling_info);
	free((*vars));
}
