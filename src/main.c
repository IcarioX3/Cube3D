/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:20:35 by icario            #+#    #+#             */
/*   Updated: 2023/07/13 12:15:21 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_game	game;
	int		i;
	
	i = 0;
	if (!(game.mlx.ptr = mlx_init()))
		exit_msg("Error\nmlx_init() failed\n");
 	if (!(game.mlx.win = mlx_new_window(game.mlx.ptr, WIDTH, HEIGHT, "cube3D")))
		exit_msg("Error\nmlx_new_window() failed\n");
	game.mlx.img = mlx_new_image(game.mlx.ptr, WIDTH, HEIGHT);
	game.mlx.addr = mlx_get_data_addr(game.mlx.img, &game.mlx.bits_per_pixel, &game.mlx.line_length, &game.mlx.endian);
	while (i < WIDTH * HEIGHT)
	{
		if (i < WIDTH * HEIGHT / 2)
			my_mlx_pixel_put(&game.mlx, i % WIDTH, i / WIDTH, 0x00FF0000);
		else
			my_mlx_pixel_put(&game.mlx, i % WIDTH, i / WIDTH, 0x0000FF00);
		i++;
	}
	//Draw a plain blue square in the middle of the screen
	int x = 0;
	int y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x > WIDTH / 2 - 100 && x < WIDTH / 2 + 100 && y > HEIGHT / 2 - 100 && y < HEIGHT / 2 + 100)
				my_mlx_pixel_put(&game.mlx, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game.mlx.ptr, game.mlx.win, game.mlx.img, 0, 0);
	mlx_hook(game.mlx.win, 17, 0, terminate, &game);
	mlx_loop(game.mlx.ptr);
	return (0);
}
