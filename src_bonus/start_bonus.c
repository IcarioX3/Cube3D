/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:56:44 by icario            #+#    #+#             */
/*   Updated: 2023/08/26 17:56:54 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"
#include "parsing_bonus.h"

int	move_mouse(int x, int y, t_game *game)
{
	mlx_mouse_get_pos(game->mlx.ptr, game->mlx.win, &x, &y);
	printf("mouse_x: %d\n", x);
	printf("mouse_y: %d\n", y);
	return (0);
}

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

void	start(t_game *game)
{
	int		mouse_x;
	int		mouse_y;

	game->floor_color = GREEN_GRASS;
	game->ceiling_color = BLUE_SKY;
	create_floor_and_ceiling(game);
	raycaster(game);
	//mlx_mouse_hide(game->mlx.ptr, game->mlx.win);
	mlx_mouse_get_pos(game->mlx.ptr, game->mlx.win, &mouse_x, &mouse_y);
	//if mouse move call function move_mouse
	mlx_hook(game->mlx.win, 6, 1L << 6, move_mouse, game);
	mlx_do_sync(game->mlx.ptr);
	mlx_hook(game->mlx.win, 2, 1L << 0, inputs, game);
	//if key is released call function key_released
	mlx_hook(game->mlx.win, 3, 1L << 1, key_released, game);
	mlx_hook(game->mlx.win, 17, 0, terminate, game);
	mlx_loop_hook(game->mlx.ptr, movements, game);
	mlx_loop(game->mlx.ptr);
}
