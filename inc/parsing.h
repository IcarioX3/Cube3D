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
	char	*mapline;
}	t_vars;


void	free_double_tab(char **args);
char	*get_map(int fd);
int parsing(t_vars **vars);

#endif