/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:52:59 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/22 14:00:18 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strdup_cub(char *s, int len)
{
	char	*cpy;
	int		i;

	if (!s)
		return (NULL);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	while (i < len)
	{
		cpy[i] = ' ';
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	find_longest_line(char **lines, int start_line)
{
	int	longest_length;
	int	i;
	int	current_length;

	longest_length = 0;
	i = start_line;
	while (lines[i] != NULL)
	{
		current_length = strlen(lines[i]);
		if (current_length > longest_length)
			longest_length = current_length;
		i++;
	}
	return (longest_length);
}

int	split_file_map(t_vars **vars)
{
	int		i;
	char	**tmp;
	int		len;

	i = -1;
	len = 0;
	(*vars)->longest_line = find_longest_line((*vars)->map, 6);
	if (vars == NULL || *vars == NULL)
		return (1);
	(*vars)->map_info = malloc(7 * sizeof(char *));
	if ((*vars)->map_info == NULL)
		return (1);
	while (++i < 6)
		(*vars)->map_info[i] = ft_strdup((*vars)->map[i]);
	(*vars)->map_info[i] = NULL;
	while ((*vars)->map[len])
		len++;
	tmp = malloc((len - 6 + 1) * sizeof(char *));
	i = -1;
	while (++i < len - 6)
		tmp[i] = ft_strdup_cub((*vars)->map[i + 6], (*vars)->longest_line);
	free_double_tab((*vars)->map);
	(*vars)->map = tmp;
	(*vars)->map[i] = NULL;
	return (0);
}
