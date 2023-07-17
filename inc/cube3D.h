/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:19:14 by icario            #+#    #+#             */
/*   Updated: 2023/07/17 15:24:57 by antoine          ###   ########.fr       */
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
# define TITLE "CUBE3D"

# define BLUE_SKY 0x87CEEB
# define GREEN_GRASS 0x00FF00

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

typedef struct s_game
{
	t_mlx	mlx;
	int		floor_color;
	int		ceiling_color;
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}t_game;

//PROTOTYPES

void	start(t_game *game);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

//CLEAN
void	clean_mlx(t_mlx *mlx);
void	clean_img(t_mlx *mlx);
int		terminate(t_game *game);

//ERROR
void	exit_msg(char *msg, t_game *game);
//INIT
void	init(t_game *game);
void	init_mlx_struct(t_mlx *mlx);
void	init_game_struct(t_game *game);
void	init_mlx(t_game *game);

#endif
