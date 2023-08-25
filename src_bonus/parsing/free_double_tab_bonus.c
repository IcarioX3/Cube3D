/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_tab_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:45:21 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:45:40 by icario           ###   ########.fr       */
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
