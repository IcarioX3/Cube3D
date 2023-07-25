/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:32:30 by icario            #+#    #+#             */
/*   Updated: 2023/07/25 14:51:17 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int	terminate(t_game *game)
{
 	clean_img(game);
	clean_mlx(game);
	exit(EXIT_SUCCESS);
	return (0);
}
