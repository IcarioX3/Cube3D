/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablevin <ablevin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:53:53 by ablevin           #+#    #+#             */
/*   Updated: 2023/08/28 17:06:08 by ablevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

long	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000 + current_time.tv_usec / 1000) / 100);
}

void	shade(t_game *game)
{
	long	current_time;

	current_time = get_current_time() % 10;
	if (current_time > 5)
		game->shade = 0.9 - (current_time - 10) * 0.01;
	else
		game->shade = 0.9 + current_time * 0.01;
}
