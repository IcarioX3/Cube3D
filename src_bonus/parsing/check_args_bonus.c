/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:20:37 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:20:59 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

int	check_args(char *av)
{
	size_t	len;

	len = strlen(av);
	if (len < 4 || strcmp(av + len - 4, ".cub") != 0)
		return (write(2, "Error: File must have extension\".cub\"\n", 38), 1);
	return (0);
}
