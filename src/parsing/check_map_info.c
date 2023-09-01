/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:19:21 by ablevin           #+#    #+#             */
/*   Updated: 2023/08/31 16:07:40 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_double_line(char **lines, t_info *info)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(lines[i], "NO ", 3) == 0)
			info->no++;
		else if (ft_strncmp(lines[i], "SO ", 3) == 0)
			info->so++;
		else if (ft_strncmp(lines[i], "WE ", 3) == 0)
			info->we++;
		else if (ft_strncmp(lines[i], "EA ", 3) == 0)
			info->ea++;
		else if (ft_strncmp(lines[i], "F ", 2) == 0)
			info->f++;
		else if (ft_strncmp(lines[i], "C ", 2) == 0)
			info->c++;
		i++;
	}
	if (info->no != 1 || info->so != 1 || info->we > 1 || info->ea != 1
		|| info->f != 1 || info->c != 1)
		return (1);
	return (0);
}

int	check_first_six_lines(char **lines, char **expected, t_info *info, int i)
{
	int		found_line;
	int		j;

	found_line = 0;
	while (i < 6 && lines[i])
	{
		j = 0;
		while (j < 6)
		{
			if (ft_strncmp(lines[i], expected[j],
					ft_strlen(expected[j])) == 0)
			{
				found_line++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (check_double_line(lines, info) == 1)
		return (1);
	if (found_line != 6)
		return (1);
	return (0);
}

void	clean_file(t_vars **vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*vars)->file_texture[i] = NULL;
		i++;
	}
}

int	check_file(t_vars **vars, char **map)
{
	int		i;
	char	*expected_lines[6];
	t_info	info;

	i = 0;
	expected_lines[0] = "NO ";
	expected_lines[1] = "SO ";
	expected_lines[2] = "WE ";
	expected_lines[3] = "EA ";
	expected_lines[4] = "F ";
	expected_lines[5] = "C ";
	info.no = 0;
	info.so = 0;
	info.we = 0;
	info.ea = 0;
	info.f = 0;
	info.c = 0;
	(*vars)->map_info = NULL;
	while (map[i])
		i++;
	if (i < 9)
		return (write (2, "Error : Wrong information\n", 26), 1);
	if (check_first_six_lines(map, expected_lines, &info, 0) == 1)
		return (write (2, "Error : Wrong information\n", 26), 1);
	return (0);
}
