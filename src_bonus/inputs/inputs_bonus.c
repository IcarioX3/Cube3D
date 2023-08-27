/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:17:32 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 20:13:07 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

//Move camera to the right or to the left depending on the mouse movement
void	mouse_move(t_game *game)
{
	int			x;
	int			y;
	static int	old_x = WIDTH / 2;

	mlx_mouse_get_pos(game->mlx.ptr, game->mlx.win, &x, &y);
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	if (x == old_x)
		return ;
	else if (x < old_x)
		rotate_left(game, ROT_SPEED * 2);
	else if (x > old_x)
		rotate_right(game, ROT_SPEED * 2);
	old_x = x;
}

//open door if player is in front of it at a distance of one block
void	open_and_close_door(t_game *game)
{
	int	x;
	int	y;

	x = (int)(game->player.pos_x + game->player.dir_x);
	y = (int)(game->player.pos_y + game->player.dir_y);
	if (game->vars->map[x][y] == '2')
		game->vars->map[x][y] = '3';
	else if (game->vars->map[x][y] == '3')
		game->vars->map[x][y] = '2';
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
	if (key == SPACE_KEY)
		open_and_close_door(game);
	return (0);
}
