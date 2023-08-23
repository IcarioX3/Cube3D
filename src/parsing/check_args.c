/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:02:07 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/23 11:24:50 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_args(char *av)
{
	size_t	len;

	len = strlen(av);
	if (len < 4 || strcmp(av + len - 4, ".cub") != 0)
		return (write(2, "Error: File must have extension\".cub\"\n", 38), 1);
	return (0);
}
