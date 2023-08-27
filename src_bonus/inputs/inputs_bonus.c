/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:17:32 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 16:40:51 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	mouse_move(t_game *game)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game->mlx.ptr, game->mlx.win, &x, &y);
	if (game->player.old_x == x)
		game->player.old_x = x;
	else if (game->player.old_x > x
		&& y < HEIGHT && x < WIDTH && x > 0 && y > 0)
	{
		rotate_left(game, ROT_SPEED * (game->player.old_x - x)
			/ game->player.old_x * 3);
		game->player.old_x -= 1;
	}
	else if (game->player.old_x < x
		&& y < HEIGHT && x < WIDTH && x > 0 && y > 0)
	{
		rotate_right(game, ROT_SPEED * (x - game->player.old_x)
			/ game->player.old_x * 3);
		game->player.old_x += 1;
	}
}

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
