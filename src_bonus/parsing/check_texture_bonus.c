/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:00:38 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/28 17:11:02 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	init_texture_info(t_vars **vars)
{
	int	i;

	i = 0;
	while ((*vars)->map_info[i])
	{
		if ((*vars)->map_info[i][0] == 'F')
		{
			(*vars)->floor_info = ft_strdup((*vars)->map_info[i]);
			if ((*vars)->floor_info == NULL)
				return (1);
		}
		if ((*vars)->map_info[i][0] == 'C')
		{
			(*vars)->ceiling_info = ft_strdup((*vars)->map_info[i]);
			if ((*vars)->ceiling_info == NULL)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_cf_info2(int coma, int i, char *ceiling)
{
	while (ceiling[i])
	{
		if ((ceiling[i] >= '0' && ceiling[i] <= '9') || ceiling[i] == ','
			|| ceiling[i] == ' ')
		{
			if (ceiling[i] == ',')
			{
				if (ceiling[i + 1] == ',')
					return (write (2, "Error : wrong texture input\n", 29), 1);
				coma++;
			}
			i++;
		}
		else
			return (write (2, "Error : wrong texture input\n", 29), 1);
	}
	if (coma != 2 || ceiling[i - 1] == ',')
		return (write (2, "Error : wrong texture input\n", 28), 1);
	return (0);
}

int	check_cf_info(char *ceiling)
{
	int	i;

	i = 1;
	while (ceiling[i] == ' ')
		i++;
	if (ceiling[i] == ',')
		return (write (2, "Error : wrong texture input\n", 29), 1);
	if (check_cf_info2(0, i, ceiling) == 1)
		return (1);
	return (0);
}

int	check_texture(t_vars **vars)
{
	if (init_texture_info(vars) == 1)
		return (1);
	if (check_cf_info((*vars)->floor_info) == 1)
		return (1);
	if (check_cf_info((*vars)->ceiling_info) == 1)
		return (1);
	if (check_texture_overflow(vars) == 1)
		return (1);
	if (check_file_texture((*vars)->map_info, vars) == 1)
		return (1);
	return (0);
}
