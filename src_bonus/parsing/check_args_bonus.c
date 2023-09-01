/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:02:07 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/31 16:17:58 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	check_args(char *av)
{
	size_t	len;

	len = ft_strlen(av);
	if (len < 4 || ft_strcmp(av + len - 4, ".cub") == 0)
		return (write(2, "Error: File must have extension\".cub\"\n", 38), 1);
	return (0);
}
