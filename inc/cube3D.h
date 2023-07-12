/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:19:14 by icario            #+#    #+#             */
/*   Updated: 2023/07/12 19:00:34 by icario           ###   ########.fr       */
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
}t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
}t_game;

//PROTOTYPES

void	exit_msg(char *msg);

#endif
