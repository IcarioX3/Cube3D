/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:18:31 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 18:52:19 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	move_forward(t_game *game)
{
	if ((game->vars->map[(int)(game->player.pos_x + game->player.dir_x
				* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0'
		&& game->vars->map[(int)(game->player.pos_x + game->player.dir_x
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0')
		|| (game->vars->map[(int)(game->player.pos_x + game->player.dir_x
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '3'))
		game->player.pos_x += game->player.dir_x * MOVE_SPEED * 4;
	if ((game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			+ game->player.dir_y * MOVE_SPEED * 4)] == '0'
		&& game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			+ game->player.dir_y * MOVE_SPEED * 4)] == '0')
		|| (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			+ game->player.dir_y * MOVE_SPEED * 4)] == '3'))
			game->player.pos_y += game->player.dir_y * MOVE_SPEED * 4;
}

void	move_backward(t_game *game)
{
	if ((game->vars->map[(int)(game->player.pos_x - game->player.dir_x
				* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0'
		&& game->vars->map[(int)(game->player.pos_x - game->player.dir_x
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0')
		|| (game->vars->map[(int)(game->player.pos_x - game->player.dir_x
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '3'))
		game->player.pos_x -= game->player.dir_x * MOVE_SPEED * 4;
	if ((game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			- game->player.dir_y * MOVE_SPEED * 4)] == '0'
		&& game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			- game->player.dir_y * MOVE_SPEED * 4)] == '0')
		|| (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			- game->player.dir_y * MOVE_SPEED * 4)] == '3'))
		game->player.pos_y -= game->player.dir_y * MOVE_SPEED * 4;
}

void	move_left(t_game *game)
{
	if ((game->vars->map[(int)(game->player.pos_x - game->player.dir_y
				* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0'
		&& game->vars->map[(int)(game->player.pos_x - game->player.dir_y
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0')
		|| (game->vars->map[(int)(game->player.pos_x - game->player.dir_y
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '3'))
		game->player.pos_x -= game->player.dir_y * MOVE_SPEED * 4;
	if ((game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			+ game->player.dir_x * MOVE_SPEED * 4)] == '0'
		&& game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			+ game->player.dir_x * MOVE_SPEED * 4)] == '0')
		|| (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			+ game->player.dir_x * MOVE_SPEED * 4)] == '3'))
		game->player.pos_y += game->player.dir_x * MOVE_SPEED * 4;
}

void	move_right(t_game *game)
{
	if ((game->vars->map[(int)(game->player.pos_x + game->player.dir_y
				* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0'
		&& game->vars->map[(int)(game->player.pos_x + game->player.dir_y
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '0')
		|| (game->vars->map[(int)(game->player.pos_x + game->player.dir_y
			* MOVE_SPEED * 4)][(int)game->player.pos_y] == '3'))
		game->player.pos_x += game->player.dir_y * MOVE_SPEED * 4;
	if ((game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			- game->player.dir_x * MOVE_SPEED * 4)] == '0'
		&& game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			- game->player.dir_x * MOVE_SPEED * 4)] == '0')
		|| (game->vars->map[(int)game->player.pos_x][(int)(game->player.pos_y
			- game->player.dir_x * MOVE_SPEED * 4)] == '3'))
		game->player.pos_y -= game->player.dir_x * MOVE_SPEED * 4;
}

int	movements(t_game *game)
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
		rotate_right(game, ROT_SPEED);
	else if (game->player.can_rotate == -1)
		rotate_left(game, ROT_SPEED);
	mouse_move(game);
	raycaster(game);
	draw_minimap(game);
	return (0);
}
