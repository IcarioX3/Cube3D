/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:32:30 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 16:40:28 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	terminate(t_game *game)
{
	clean_img(game);
	clean_mlx(game);
	clean_parsing(game);
	exit(EXIT_SUCCESS);
	return (0);
}
