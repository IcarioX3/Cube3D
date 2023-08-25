/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:52:38 by frgojard          #+#    #+#             */
/*   Updated: 2023/08/25 15:44:38 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_vars
{
	char	**map;
	char	**map_info;
	char	*floor_info;
	char	*ceiling_info;
	char	*mapline;
	char	**file_texture;
	int		longest_line;
	int		floor[3];
	int		ceiling[3];
	int		begin_x;
	int		begin_y;
	char	player;
}	t_vars;

typedef struct s_info
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_info;

void	free_double_tab(char **args);
char	*get_map(int fd);
int		parsing(t_vars **vars);
int		split_file_map(t_vars **vars);
int		check_map(t_vars **vars, char **map, int nb_player);
int		check_file(t_vars **vars, char **map);
int		check_texture_overflow(t_vars **vars);
int		check_texture(t_vars **vars);
int		check_args(char *av);
int		fill(char **map);
int		check_file_texture(char **map_info, t_vars **vars);
void	clean_parsing1(t_vars **vars);
int	init_parsing(t_vars **vars, char **av, int fd);

#endif