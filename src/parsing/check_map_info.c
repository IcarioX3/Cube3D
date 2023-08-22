/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:51:01 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/22 14:38:34 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// int	check_double_line(char **lines, char **expected_line)
// {
// 	int		i;
// 	int		j;
// 	int flag;
	
// 	i = 0;
// 	j = 0;
// 	flag = 0;
// 	while (i < 6 && lines[i])
// 	{
// 		while (j < 6 && lines[j])
// 		{
// 			if (strncmp(lines[i], lines[j],
// 					ft_strlen(expected_line[j])) == 0)
// 			{
// 				if (flag >= 2)
// 					return (1);
// 				flag++;
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}	
// 	return (0);
// }

int	check_first_six_lines(char **lines, char **expected_lines)
{
	int		found_line;
	int		i;
	int		j;

	found_line = 0;
	i = 0;
	while (i < 6 && lines[i])
	{
		j = 0;
		while (j < 6)
		{
			if (strncmp(lines[i], expected_lines[j],
					ft_strlen(expected_lines[j])) == 0)
			{
				found_line++;
				break ;
			}
			// if (check_double_line(lines, expected_lines) == 1)
			// 	return (1);
			j++;
		}
		i++;
	}
	if (found_line != 6)
		return (1);
	return (0);
}

int	check_file(t_vars **vars, char **map)
{
	int		i;
	char	*expected_lines[6];

	i = 0;
	expected_lines[0] = "NO ";
	expected_lines[1] = "SO ";
	expected_lines[2] = "WE ";
	expected_lines[3] = "EA ";
	expected_lines[4] = "F ";
	expected_lines[5] = "C ";
	(*vars)->map_info = NULL;
	while (map[i])
		i++;
	if (i < 9)
		return (write (2, "Error : Wrong information\n", 26), 1);
	if (check_first_six_lines(map, expected_lines) == 1)
		return (write (2, "Error : Wrong information\n", 26), 1);
	return (0);
}
