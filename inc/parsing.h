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
	int		longest_line;
	int		begin_x;
	int		begin_y;
	char	player;
}	t_vars;


void	free_double_tab(char **args);
char	*get_map(int fd);
int parsing(t_vars **vars, char **av);
int    split_file_map(t_vars **vars);
int check_map(t_vars **vars, char **map);

#endif