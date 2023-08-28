/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_info_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franck <franck@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:38:04 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 20:07:31 by franck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	remove_until_first_digit_ceiling(t_vars **vars, char *str)
{
	int		len;
	int		start;
	char	*cpy;
	char	*ptr;

	len = 0;
	start = -1;
	cpy = NULL;
	if (str == NULL || *str == '\0')
		return (1);
	ptr = str;
	while (str[++start] && !isdigit(*str))
		str++;
	while (*str)
	{
		len++;
		str++;
	}
	str = ptr;
	cpy = ft_substr(str, start, len);
	if (!cpy)
		return (1);
	free ((*vars)->ceiling_info);
	(*vars)->ceiling_info = cpy;
	return (0);
}

int	remove_until_first_digit_floor(t_vars **vars, char *str)
{
	int		len;
	int		start;
	char	*cpy;
	char	*ptr;

	len = 0;
	start = -1;
	cpy = NULL;
	if (str == NULL || *str == '\0')
		return (1);
	ptr = str;
	while (str[++start] && !isdigit(*str))
		str++;
	while (*str)
	{
		len++;
		str++;
	}
	str = ptr;
	cpy = ft_substr(str, start, len);
	if (!cpy)
		return (1);
	free ((*vars)->floor_info);
	(*vars)->floor_info = cpy;
	return (0);
}

int	check_overflow(char *str, int info[], int i)
{
	char	**split;
	int		len;
	int		tab[3];

	len = -1;
	split = NULL;
	split = ft_split(str, ',');
	while (++i < 3)
	{
		while (split[i][++len])
			if (len > 2 && split[i][len] != ' ')
				return (free_double_tab(split),
					write (2, "error: textures not between 0 and 255\n", 39), 1);
		len = 0;
		tab[i] = ft_atoi(split[i]);
		info[i] = ft_atoi(split[i]);
		if (tab[i] > 255)
		{
			free_double_tab(split);
			return (write (2, "error: textures not between 0 and 255\n", 39), 1);
		}
	}
	free_double_tab(split);
	return (0);
}

int	check_texture_overflow(t_vars **vars)
{
	if (remove_until_first_digit_ceiling(vars, (*vars)->ceiling_info) == 1)
		return (1);
	if (remove_until_first_digit_floor(vars, (*vars)->floor_info) == 1)
		return (1);
	if (check_overflow((*vars)->floor_info, (*vars)->floor, -1) == 1)
		return (1);
	if (check_overflow((*vars)->ceiling_info, (*vars)->ceiling, -1) == 1)
		return (1);
	return (0);
}
