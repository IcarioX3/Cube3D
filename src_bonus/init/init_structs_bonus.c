/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablevin <ablevin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:05:45 by icario            #+#    #+#             */
/*   Updated: 2023/08/28 14:22:38 by ablevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_game_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->textures[i].img = NULL;
		game->textures[i].addr = NULL;
		game->textures[i].bits_per_pixel = 0;
		game->textures[i].line_length = 0;
		game->textures[i].endian = 0;
		i++;
	}
	game->ceiling_color = 0;
	game->floor_color = 0;
	game->shade = 0;
}

void	init_mlx_struct(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bits_per_pixel = 0;
	mlx->line_length = 0;
	mlx->endian = 0;
}

/*Pos x and pos y are the position of the player in the map
Dir x and dir y are the direction of the player
Map x and map y are the position of the player in the map*/
//Can move directions: 0 = up, 1 = down, 2 = left, 3 = right
void	init_player_struct(t_player *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 1;
	player->dir_y = 0;
	player->map_x = 0;
	player->map_y = 0;
	player->can_move[0] = 0;
	player->can_move[1] = 0;
	player->can_move[2] = 0;
	player->can_move[3] = 0;
	player->can_rotate = 0;
}

/*Plane x and plane y are the camera plane coordinates
Camera x is the x-coordinate in camera space*/
void	init_camera_struct(t_camera *camera)
{
	camera->plane_x = 0;
	camera->plane_y = 0;
	camera->camera_x = 0;
}

/*Ray direction x and y are the direction of the ray
Side dist x and y are the distance of the ray to the next side
Delta dist x and y are the distance the ray has to travel 
	to go from 1 x-side to the next x-side or 
	from 1 y-side to the next y-side
Perp wall dist is the distance of the ray to the next wall
Step x and y are the step direction of the ray
Hit is a boolean to know if the ray hit a wall
Side is a boolean to know if the ray hit a vertical or horizontal wall*/
void	init_raycaster_struct(t_raycaster *raycaster)
{
	raycaster->ray_dir_x = 0;
	raycaster->ray_dir_y = 0;
	raycaster->side_dist_x = 0;
	raycaster->side_dist_y = 0;
	raycaster->delta_dist_x = 0;
	raycaster->delta_dist_y = 0;
	raycaster->perp_wall_dist = 0;
	raycaster->step_x = 0;
	raycaster->step_y = 0;
	raycaster->hit = 0;
	raycaster->side = 0;
	raycaster->wall_x = 0;
	raycaster->tex_x = 0;
	raycaster->tex_y = 0;
	raycaster->tex_pos = 0;
	raycaster->step = 0;
}
