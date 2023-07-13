/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:19:14 by icario            #+#    #+#             */
/*   Updated: 2023/07/13 14:50:10 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"

//DEFINES

# define WIDTH 1920
# define HEIGHT 1080

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
}t_game;

//PROTOTYPES

void	start(t_game *game);

//CLEAN
void	clean_mlx(t_mlx *mlx);
void	clean_img(t_mlx *mlx);
int		terminate(t_game *game);

//ERROR
void	exit_msg(char *msg, t_game *game);
//INIT
void	init(t_game *game);
void	init_mlx_struct(t_mlx *mlx);
void	init_mlx(t_game *game);

#endif
