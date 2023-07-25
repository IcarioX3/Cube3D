#include "parsing.h"

int check_map(t_vars **vars, char **map)
{
    int i;
    int j;
    int nb_player;

    i = 0;
    nb_player = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' 
            && map[i][j] != 'N' && map[i][j] != 'S' && map[i][j]!= 'E' 
            && map[i][j] != 'W' && map[i][j] != ' ')
                return (write (2, "Error : Wrong input map\n", 24), 1);
            if (map[i][j] == 'N' || map[i][j] == 'S' 
                || map[i][j]== 'E' || map[i][j] == 'W')
            {
                (*vars)->begin_x = i;
                (*vars)->begin_y = j;
                (*vars)->player = map[i][j];
                nb_player++;
            }
            j++;
        }
        i++;
    }
    if (nb_player == 0 || nb_player > 1)
        return (write (2, "Error : more or less than 1 player\n", 36), 1);
    return (0);
}