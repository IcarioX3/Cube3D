/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_tab_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:52:51 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/28 17:11:08 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_bonus.h"

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
