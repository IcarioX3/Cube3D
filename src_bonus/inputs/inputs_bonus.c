/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:17:32 by icario            #+#    #+#             */
/*   Updated: 2023/08/26 17:52:51 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"

int	inputs(int key, t_game *game)
{
	if (key == ESCAPE_KEY)
		terminate(game);
	if (key == W_KEY)
		game->player.can_move[0] = 1;
	else if (key == S_KEY)
		game->player.can_move[1] = 1;
	else if (key == A_KEY)
		game->player.can_move[2] = 1;
	else if (key == D_KEY)
		game->player.can_move[3] = 1;
	if (key == RIGHT_ARROW)
		game->player.can_rotate = 1;
	else if (key == LEFT_ARROW)
		game->player.can_rotate = -1;
	return (0);
}
