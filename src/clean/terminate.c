/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:32:30 by icario            #+#    #+#             */
/*   Updated: 2023/07/13 13:45:37 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	terminate(t_game *game)
{
	clean_img(&game->mlx);
	clean_mlx(&game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
