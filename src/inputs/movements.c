/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:50:52 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 16:40:28 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

void	move_forward(t_game *game)
{
	if (game->vars->map[(int)(game->player.pos_x + game->player.dir_x
			* MOVE_SPEED)][(int)game->player.pos_y] == '0')
		game->player.pos_x += game->player.dir_x * MOVE_SPEED;
	if (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
		+ game->player.dir_y * MOVE_SPEED)] == '0')
		game->player.pos_y += game->player.dir_y * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	if (game->vars->map[(int)(game->player.pos_x - game->player.dir_x
			* MOVE_SPEED)][(int)game->player.pos_y] == '0')
		game->player.pos_x -= game->player.dir_x * MOVE_SPEED;
	if (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
		- game->player.dir_y * MOVE_SPEED)] == '0')
		game->player.pos_y -= game->player.dir_y * MOVE_SPEED;
}

void	move_right(t_game *game)
{
	if (game->vars->map[(int)(game->player.pos_x + game->player.dir_y
			* MOVE_SPEED)][(int)game->player.pos_y] == '0')
		game->player.pos_x += game->player.dir_y * MOVE_SPEED;
	if (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
		- game->player.dir_x * MOVE_SPEED)] == '0')
		game->player.pos_y -= game->player.dir_x * MOVE_SPEED;
}

void	move_left(t_game *game)
{
	if (game->vars->map[(int)(game->player.pos_x - game->player.dir_y
			* MOVE_SPEED)][(int)game->player.pos_y] == '0')
		game->player.pos_x -= game->player.dir_y * MOVE_SPEED;
	if (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
		+ game->player.dir_x * MOVE_SPEED)] == '0')
		game->player.pos_y += game->player.dir_x * MOVE_SPEED;
}

int	movements(t_game *game, int key)
{
	if (game->player.can_move[0])
		move_forward(game);
	if (game->player.can_move[1])
		move_backward(game);
	if (game->player.can_move[2])
		move_left(game);
	if (game->player.can_move[3])
		move_right(game);
	if (game->player.can_rotate == 1)
		rotate_right(game);
	else if (game->player.can_rotate == -1)
		rotate_left(game);
	raycaster(game);
	return (key);
}
