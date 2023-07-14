/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:47:01 by icario            #+#    #+#             */
/*   Updated: 2023/07/14 12:48:11 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

void	create_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->mlx, x, y, game->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->mlx, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}

void	start(t_game *game)
{
	int	map[10][10] = {
    	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   		{1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
    	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
   		{1, 0, 1, 1, 0, 1, 0, 0, 0, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    	{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	int	x;
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;

	init_mlx(game);
	game->floor_color = GREEN_GRASS;
	game->ceiling_color = BLUE_SKY;
	//create_floor_and_ceiling(game);
	game->pos_x = 5;
	game->pos_y = 5;
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		ray_dir_x = game->dir_x + game->plane_x * camera_x;
		ray_dir_y = game->dir_y + game->plane_y * camera_x;
		x++;
	}
	
	//wich box of the map we're in
	int	map_x;
	int	map_y;
	
	map_x = (int)game->pos_x;
	map_y = (int)game->pos_y;
	//length of ray from current position to next x or y-side
	float	side_dist_x;
	float	side_dist_y;
	//length of ray from one x or y-side to next x or y-side
	float	delta_dist_x;
	float	delta_dist_y;
	float	perp_wall_dist;
	
	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / ray_dir_y);
	//what direction to step in x or y-direction (either +1 or -1)
	int	step_x;
	int	step_y;
	
	//was there a wall hit?
	int	hit;
	hit = 0;
	//was a NS or a EW wall hit?
	int	side;
	
	//calculate step and initial side_dist
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (game->pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - game->pos_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (game->pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - game->pos_y) * delta_dist_y;
	}
	
	//perform DDA
	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		//Check if ray has hit a wall
		if (map[map_x][map_y] > 0)
			hit = 1;
	}
	
	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
	if (side == 0)
		perp_wall_dist = (map_x - game->pos_x + (1 - step_x) / 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - game->pos_y + (1 - step_y) / 2) / ray_dir_y;
		
	printf("perp wall dist: %f\n", perp_wall_dist);
		
	//Calculate height of line to draw on screen
	int	line_height;
	line_height = (int)(HEIGHT / perp_wall_dist);
	printf("line height: %d\n", line_height);

	//calculate lowest and highest pixel to fill in current stripe
	int	draw_start;
	int	draw_end;
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	printf("draw start: %d\n", draw_start);
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
		
	//choose wall color
	int	color;
	if (map[map_x][map_y] == 1)
		color = 0xFF0000;
	else if (map[map_x][map_y] == 2)
		color = 0x00FF00;
	else if (map[map_x][map_y] == 3)
		color = 0x0000FF;
	else if (map[map_x][map_y] == 4)
		color = 0xFFFFFF;
	else
		color = 0xFFFF00;
		
	//give x and y sides different brightness
	if (side == 1)
		color = color / 2;
	
	//draw the pixels of the stripe as a vertical line
	int	y;
	y = draw_start;
	printf("draw end: %d\n", draw_end);
	printf("draw start: %d\n", draw_start);
	while (y < draw_end)
	{
		printf("HOLA\n");
		my_mlx_pixel_put(&game->mlx, x, y, color);
		y++;
	}

	

	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	mlx_hook(game->mlx.win, 17, 0, terminate, game);
	mlx_loop(game->mlx.ptr);
}
