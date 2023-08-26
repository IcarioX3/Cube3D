/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:26 by antoine           #+#    #+#             */
/*   Updated: 2023/08/26 18:16:31 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	key_released(int key, t_game *game)
{
	if (key == W_KEY)
		game->player.can_move[0] = 0;
	else if (key == S_KEY)
		game->player.can_move[1] = 0;
	else if (key == A_KEY)
		game->player.can_move[2] = 0;
	else if (key == D_KEY)
		game->player.can_move[3] = 0;
	if (key == RIGHT_ARROW || key == LEFT_ARROW)
		game->player.can_rotate = 0;
	return (0);
}

int	inputs(int key, t_game *game)
{
	if (key == ESCAPE_KEY)
		terminate(game);
	if (key == W_KEY)
		game->player.can_move[0] = 1;
	if (key == S_KEY)
		game->player.can_move[1] = 1;
	if (key == A_KEY)
		game->player.can_move[2] = 1;
	if (key == D_KEY)
		game->player.can_move[3] = 1;
	if (key == RIGHT_ARROW)
		game->player.can_rotate = 1;
	if (key == LEFT_ARROW)
		game->player.can_rotate = -1;
	return (0);
}
