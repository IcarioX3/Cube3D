#include "parsing.h"

void	free_double_tab(char **args)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (args == NULL)
		return ;
	while (args[size])
		size++;
	while (i < size)
		free(args[i++]);
	free(args);
}