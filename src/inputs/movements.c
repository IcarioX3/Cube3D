/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:35:20 by antoine           #+#    #+#             */
/*   Updated: 2023/08/14 22:04:15 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	move_forward(t_game *game)
{
	if (game->map[(int)(game->player.pos_x + game->player.dir_x
			* MOVE_SPEED)][(int)game->player.pos_y] == 0)
		game->player.pos_x += game->player.dir_x * MOVE_SPEED;
	if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
		+ game->player.dir_y * MOVE_SPEED)] == 0)
		game->player.pos_y += game->player.dir_y * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	if (game->map[(int)(game->player.pos_x - game->player.dir_x
			* MOVE_SPEED)][(int)game->player.pos_y] == 0)
		game->player.pos_x -= game->player.dir_x * MOVE_SPEED;
	if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
		- game->player.dir_y * MOVE_SPEED)] == 0)
		game->player.pos_y -= game->player.dir_y * MOVE_SPEED;
}

void	move_right(t_game *game)
{
	if (game->map[(int)(game->player.pos_x + game->player.dir_y
			* MOVE_SPEED)][(int)game->player.pos_y] == 0)
		game->player.pos_x += game->player.dir_y * MOVE_SPEED;
	if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
		- game->player.dir_x * MOVE_SPEED)] == 0)
		game->player.pos_y -= game->player.dir_x * MOVE_SPEED;
}

void	move_left(t_game *game)
{
	if (game->map[(int)(game->player.pos_x - game->player.dir_y
			* MOVE_SPEED)][(int)game->player.pos_y] == 0)
		game->player.pos_x -= game->player.dir_y * MOVE_SPEED;
	if (game->map[(int)game->player.pos_x][(int)(game->player.pos_y
		+ game->player.dir_x * MOVE_SPEED)] == 0)
		game->player.pos_y += game->player.dir_x * MOVE_SPEED;
}

void	movements(t_game *game, int key)
{
	if (key == W_KEY)
		move_forward(game);
	if (key == S_KEY)
		move_backward(game);
	if (key == D_KEY)
		move_right(game);
	if (key == A_KEY)
		move_left(game);
}