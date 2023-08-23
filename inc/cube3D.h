/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:19:14 by icario            #+#    #+#             */
/*   Updated: 2023/08/14 22:00:24 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

//DEFINES

# define WIDTH 1920
# define HEIGHT 1080
# define CAMERA_PLANE_X 0
# define CAMERA_PLANE_Y 0.8
# define TITLE "CUBE3D"
# define MOVE_SPEED 0.08
# define ROT_SPEED 0.04

# define BLUE_SKY 0x87CEEB
# define GREEN_GRASS 0x00FF00

# define ESCAPE_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

//STRUCTS

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_mlx;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
}t_player;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	camera_x;
}t_camera;

typedef struct s_raycaster
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}t_raycaster;

typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_camera	camera;
	t_raycaster	raycaster;
	int			floor_color;
	int			ceiling_color;
	int			map[10][10];
}t_game;

//PROTOTYPES

void	start(t_game *game);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

//CLEAN
void	clean_mlx(t_game *game);
void	clean_img(t_game *game);
int		terminate(t_game *game);

//ERROR
void	exit_msg(char *msg, t_game *game);
//INIT
void	init(t_game *game);
void	init_mlx_struct(t_mlx *mlx);
void	init_game_struct(t_game *game);
void	init_player_struct(t_player *player);
void	init_camera_struct(t_camera *camera);
void	init_raycaster_struct(t_raycaster *raycaster);
void	init_mlx(t_game *game);
void	init_game(t_game *game);
//RAYCASTER
void	raycaster(t_game *game);
void	draw_pixels(t_game *game, int x);
void	create_floor_and_ceiling(t_game *game);
//INPUTS
int		inputs(int key, t_game *game);
void	movements(t_game *game, int key);
void	rotate(t_game *game, int key);

#endif
