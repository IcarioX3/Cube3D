#include "parsing.h"

int check_first_six_lines(char** lines) 
{
    int found_line;
    int i;
    int j;
    char expected_lines[6][4] = { "NO ", "SO ", "WE ", "EA ", "F ", "C " };

    found_line = 0;
    i = 0;

    while (i < 6 && lines[i])
    {
        j = 0;
        while (j < 6)
        {
            if (strncmp(lines[i], expected_lines[j], ft_strlen(expected_lines[j])) == 0)
            {
                found_line++;
                break;
            }
            j++;
        }
        i++;
    }
    if (found_line != 6)
        return (1);
    return (0);
}

int check_file(t_vars **vars, char **map)
{
    int i;
    i = 0;
    (*vars)->map_info = NULL;
    while(map[i])
        i++;
    if (i < 9)
        return (write (2, "Error : Wrong input map\n", 24), 1);
    if (check_first_six_lines(map) == 1)
        return (write (2, "Error : Wrong information\n", 26), 1);
    return (0);
}

int fill(char** map) 
{
    if (map == NULL) 
    {
        return 1;
    }

    // Vérifier les voisins pour chaque cellule du tableau
    int i = 0;
    while (map[i] != NULL) {
        int j = 0;
        while (map[i][j] != '\0') {
            char c = map[i][j];
            if (c == '0' || c == 'S' || c == 'N' || c == 'E' || c == 'W') {
                // Vérification des voisins
                int has_neighbor = 0;

                // Voisin au-dessus
                if (i > 0 && map[i - 1][j] == ' ')
                    has_neighbor = 1;
                
                // Voisin en dessous
                if (map[i + 1] == NULL )
                    has_neighbor = 1;
                else if (map[i + 1][j] == ' ')
                    has_neighbor = 1;

                // Voisin à gauche
                if (j > 0 && map[i][j - 1] == ' ')
                    has_neighbor = 1;

                // Voisin à droite
                if (map[i][j + 1] == '\0' && map[i][j + 1] == ' ')
                    has_neighbor = 1;

                // Si un des voisins est différent d'un espace
                if (has_neighbor == 1) {
                    return (write (2, "Error : there must be walls all around\n", 40), 1);
                }
            }
            j++;
        }
        i++;
    }

    return 0;
}

int parsing(t_vars **vars)
{
    (void)vars;
    if (check_file(vars, (*vars)->map) == 1)
        return (1);
    if (split_file_map(vars) == 1)
        return (1);
    if (check_map(vars ,(*vars)->map) == 1)
        return (1);
    if (fill((*vars)->map) == 1)
        return (1);
    return (0);
}