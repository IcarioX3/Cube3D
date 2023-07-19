/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:47:01 by icario            #+#    #+#             */
/*   Updated: 2023/07/19 22:56:57 by antoine          ###   ########.fr       */
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
   		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   		{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    	{1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    	{1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    	{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	init_mlx(game);
	game->floor_color = GREEN_GRASS;
	game->ceiling_color = BLUE_SKY;
	create_floor_and_ceiling(game);

	//counter for x (WIDTH) and y (HEIGHT) pixels
	int	x;
	int	y;
	//x and y starting pos
	double	posX;
	double	posY;
	//initial direction vector
	double	dirX;
	double	dirY;
	//2d raycaster version of camera
	double	planeX;
	double	planeY;
	//x coordinate in camera space
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	//wich box of the map we're in
	int	mapX;
	int	mapY;
	//length of ray from current position to next x or y-side
	double	sideDistX;
	double	sideDistY;
	//length of ray from one x or y-side to next x or y-side
	double deltaDistX;
	double deltaDistY;
	
	double	perpWallDist;

	//which direction to step in x or y-direction (either +1 or -1)
	int	stepX;
	int	stepY;
	//was there a wall hit ?
	int	hit;
	//was it a NS or EW wall hit ?
	int	side;
	//height of line on screen
	int lineHeight;
	//lowest and highest pixel to fill in current stripe
	int drawStart;
	int	drawEnd;
			
	x = 0;
	posX = 3;
	posY = 3;
	dirX = 0.5;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;

	while (x < WIDTH)
	{
		cameraX = 2 * x / (double)WIDTH - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		mapX = (int)posX;
		mapY = (int)posY;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		hit = 0;
		
		//printf("x = %d\n", x);
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		
		//perform DDA
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//check if ray has hit a wall
			if (map[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculated distance projected on camera direction
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		//calculate heigth of line to draw on screen
		lineHeight = (int)(HEIGHT / perpWallDist);
		//calculate the lowest and highest pixel to fill in current stripe
		drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		y = drawStart;
		//printf("drawStart = %d\n", drawStart);
		while (y < drawEnd)
		{
			//printf("y = %d\n", y);
			if (side)
				my_mlx_pixel_put(&game->mlx, x, y, 0xFF0000);
			else
				my_mlx_pixel_put(&game->mlx, x, y, 0xBB0000);
			y++;
		}
		x++;
	}

/* 	game->pos_x = 5;
	game->pos_y = 5;
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 1;
	
	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (float)WIDTH - 1;
		ray_dir_x = game->dir_x + game->plane_x * camera_x;
		ray_dir_y = game->dir_y + game->plane_y * camera_x;

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
		//Calculate height of line to draw on screen
		int	line_height;
		line_height = (int)(HEIGHT / perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int	draw_start;
		int	draw_end;
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
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
		while (y < draw_end)
		{
			my_mlx_pixel_put(&game->mlx, x, y, color);
			y++;
		}
		x++;
	} */

	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	mlx_hook(game->mlx.win, 17, 0, terminate, game);
	mlx_loop(game->mlx.ptr);
}
