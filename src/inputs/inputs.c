/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:26 by antoine           #+#    #+#             */
/*   Updated: 2023/08/14 22:00:01 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

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
