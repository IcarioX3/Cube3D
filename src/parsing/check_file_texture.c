/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:13:22 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/28 17:00:43 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*init_texture_var(char *info)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	str = NULL;
	while (info[i] != ' ')
		i++;
	while (info[i] == ' ')
		i++;
	if (info[i] != '\0')
	{
		len = i;
		while (info[len] != ' ' && info[len])
			len++;
		len = len - i;
		str = ft_substr(info, i, len);
	}
	else
		return (NULL);
	return (str);
}

int	check_open_file(char **file_texture)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(file_texture[i], O_RDONLY);
		if (fd < 0)
			return (write(2, "error: can't open the texture file\n", 36), 1);
		i++;
	}
	return (0);
}

int	check_file_texture(char **map_info, t_vars **vars)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (strncmp(map_info[i], "NO ", 3) == 0)
			(*vars)->file_texture[0] = init_texture_var(map_info[i]);
		else if (strncmp(map_info[i], "SO ", 3) == 0)
			(*vars)->file_texture[1] = init_texture_var(map_info[i]);
		else if (strncmp(map_info[i], "WE ", 3) == 0)
			(*vars)->file_texture[3] = init_texture_var(map_info[i]);
		else if (strncmp(map_info[i], "EA ", 3) == 0)
			(*vars)->file_texture[2] = init_texture_var(map_info[i]);
		i++;
	}
	if (check_open_file((*vars)->file_texture) == 1)
		return (1);
	return (0);
}
