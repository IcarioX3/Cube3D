/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:17:32 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:17:55 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"

int	inputs(int key, t_game *game)
{
	if (key == ESCAPE_KEY)
		terminate(game);
	if (key == W_KEY || key == S_KEY || key == A_KEY || key == D_KEY)
		movements(game, key);
	if (key == RIGHT_ARROW || key == LEFT_ARROW)
		rotate(game, key);
	raycaster(game);
	return (0);
}
