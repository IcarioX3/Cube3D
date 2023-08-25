/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franck <franck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:00:38 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/24 17:54:22 by franck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

char *init_texture_var(char *info)
{
	char *str = NULL;
	int i = 0;
	int len;
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

int check_open_file(char **file_texture)
{
	int i;
	int fd;

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
	int i;

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
	(*vars)->file_texture = NULL;
	(*vars)->file_texture = malloc(4 * sizeof(char *));
	if (check_file_texture((*vars)->map_info, vars) == 1)
		return (1);
	return (0);
}
