/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:52:51 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/25 14:47:45 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_double_tab(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (args == NULL)
		return ;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}
