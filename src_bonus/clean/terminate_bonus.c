/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:01:58 by icario            #+#    #+#             */
/*   Updated: 2023/08/25 19:02:18 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D_bonus.h"

int	terminate(t_game *game)
{
	clean_img(game);
	clean_mlx(game);
	clean_parsing(game);
	exit(EXIT_SUCCESS);
	return (0);
}
