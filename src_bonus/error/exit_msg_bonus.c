/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icario <icario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:02:48 by icario            #+#    #+#             */
/*   Updated: 2023/08/27 16:40:51 by icario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	exit_msg(char *msg, t_game *game)
{
	ft_putstr_fd(msg, 2);
	terminate(game);
	exit(EXIT_FAILURE);
}
