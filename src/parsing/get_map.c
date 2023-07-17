#include "parsing.h"

char	*get_map(int fd)
{
	char	*mapgnl;
	char	*map;

	mapgnl = NULL;
	map = NULL;
	if (mapgnl == NULL)
	{
		mapgnl = get_next_line(fd);
		if (mapgnl == NULL)
			return (NULL);
		map = ft_strdup(mapgnl);
		if (map == NULL)
		{
			free(mapgnl);
			return (NULL);
		}
		free(mapgnl);
	}
	while (mapgnl != NULL)
	{
		mapgnl = get_next_line(fd);
		if (mapgnl != NULL)
			map = ft_strjoin(map, mapgnl);
		free(mapgnl);
	}
	return (map);
}
