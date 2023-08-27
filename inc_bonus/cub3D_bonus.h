/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:28:51 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 15:59:18 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_BONUS_H
# define CUBE3D_BONUS_H

# include "libft.h"
# include "mlx.h"
# include "parsing_bonus.h"
# include <math.h>

//DEFINES

# define TITLE "CUBE3D"
# define WIDTH 960
# define HEIGHT 540
# define MOVE_SPEED 0.04
# define ROT_SPEED 0.03

# define BLUE_SKY 0x87CEEB
# define GREEN_GRASS 0x00FF00
# define TEX_WIDTH 16

# define ESCAPE_KEY 65307
# define SPACE_KEY 32
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
	int		can_move[4];
	int		can_rotate;
	int		old_x;
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
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}t_raycaster;

typedef struct s_tex
{
	char	*filename;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_tex;

typedef struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_camera	camera;
	t_raycaster	raycaster;
	t_tex		textures[4];
	t_vars		*vars;
	int			floor_color;
	int			ceiling_color;
}t_game;

//PROTOTYPES

void	start(t_game *game);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

//CLEAN
void	clean_mlx(t_game *game);
void	clean_img(t_game *game);
void	clean_parsing(t_game *game);
int		terminate(t_game *game);

//ERROR
void	exit_msg(char *msg, t_game *game);
//INIT
void	init(t_game *game, t_vars *vars);
void	init_mlx_struct(t_mlx *mlx);
void	init_game_struct(t_game *game);
void	init_player_struct(t_player *player);
void	init_camera_struct(t_camera *camera);
void	init_raycaster_struct(t_raycaster *raycaster);
void	init_mlx(t_game *game);
void	init_tex_struct(t_game *game);
void	init_game(t_game *game, t_vars *vars);
void	init_textures(t_game *game);
//RAYCASTER
void	raycaster(t_game *game);
void	draw_pixels(t_game *game, int x);
void	create_floor_and_ceiling(t_game *game);
void	draw_minimap(t_game *game);
//INPUTS
int		inputs(int key, t_game *game);
void	mouse_move(t_game *game);
int		movements(t_game *game);
void	rotate_left(t_game *game, double speed);
void	rotate_right(t_game *game, double speed);

#endif
