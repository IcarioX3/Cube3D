/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:52:56 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/23 12:06:01 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing(t_vars **vars)
{
	if (check_file(vars, (*vars)->map) == 1)
		return (1);
	if (split_file_map(vars) == 1)
		return (1);
	if (check_map(vars, (*vars)->map, 0) == 1)
		return (1);
	if (fill((*vars)->map) == 1)
		return (1);
	if (check_texture(vars) == 1)
		return (1);
	return (0);
}
