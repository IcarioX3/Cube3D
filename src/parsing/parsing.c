#include "parsing.h"

int    split_file_map(t_vars **vars)
{
    int i;
    char **tmp;
    int len;

    i = 0;
    len = 0;
    if (vars == NULL || *vars == NULL)
        return (1);
    (*vars)->map_info = malloc(7 * sizeof(char*));
    if ((*vars)->map_info == NULL)
        return (1);
    while (i < 6)
    {
        (*vars)->map_info[i] = ft_strdup((*vars)->map[i]);
        i++;
    }
    (*vars)->map_info[i] = NULL;
    while ((*vars)->map[len])
        len++;
    tmp = malloc((len - 6 + 1) * sizeof(char*));
    i = 0;
    while (i < len - 6)
    {
        tmp[i] = ft_strdup((*vars)->map[i + 6]);
        i++;
    }
    free_double_tab((*vars)->map);
    (*vars)->map = tmp;
    (*vars)->map[i] = NULL;
    return (0);
}

int parsing(t_vars **vars)
{
    (void)vars;
    split_file_map(vars);
    return (0);
}