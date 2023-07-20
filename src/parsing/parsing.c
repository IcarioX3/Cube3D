#include "parsing.h"

int parsing(t_vars **vars)
{
    (void)vars;
    if (split_file_map(vars) == 1)
        return (1);
    if (check_map(vars ,(*vars)->map) == 1)
        return (1);
    return (0);
}