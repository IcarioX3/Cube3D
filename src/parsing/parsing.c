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

int check_args(char *av) {
    // Vérifier que le nom de fichier se termine par ".cub"
    size_t len = strlen(av);
    if (len < 4 || strcmp(av + len - 4, ".cub") != 0) {
        // Le nom de fichier ne se termine pas par ".cub"
        write(STDERR_FILENO, "Erreur : Le fichier doit avoir l'extension \".cub\"\n", 48);
        return 1;
    }

    // Tentative d'ouverture du fichier
    int fd = open(av, O_RDONLY);
    if (fd == -1) {
        // Gestion des erreurs d'ouverture de fichier
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Fermer le fichier après l'ouverture réussie (facultatif)
    close(fd);

    return 0; // Pas d'erreur
}

int init_texture_info(t_vars **vars) 
{
    int i;

    i = 0;
    (*vars)->ceiling_info = NULL;
    (*vars)->floor_info = NULL;

    while ((*vars)->map_info[i])
    {
        if ((*vars)->map_info[i][0] == 'F')
        {
            (*vars)->floor_info = strdup((*vars)->map_info[i]);
            if ((*vars)->floor_info == NULL)
                return (1);
        }
        if ((*vars)->map_info[i][0] == 'C')
        {
            (*vars)->ceiling_info = strdup((*vars)->map_info[i]);
            if ((*vars)->ceiling_info == NULL)
                return (1);
        }
        i++;
    }
    return 0;
}

int check_floor_info(char *floor)
{
    int i;
    int coma;

    coma = 0;
    i = 1;
    while (floor[i] == ' ')
        i++;
    while(floor[i])
    {
        if ((floor[i] >= '0' && floor[i] <= '9') || floor[i] == ',')
        {
            if (floor[i] == ',')
            {
                if (floor[i + 1] == ',')
                    return (write (2, "Error : wrong texture input\n", 29), 1);
                coma++;
            }
            i++;
        }
        else
            return (write (2, "Error : wrong texture input\n", 29), 1);
    }
    if (coma != 2 || floor[i - 1] == ',')
        return (write (2, "Error : wrong texture input\n", 28), 1);
    return (0);
}

int check_ceiling_info(char *ceiling)
{
    int i;
    int coma;

    coma = 0;
    i = 1;
    while (ceiling[i] == ' ')
        i++;
    while(ceiling[i])
    {
        if ((ceiling[i] >= '0' && ceiling[i] <= '9') || ceiling[i] == ',')
        {
            if (ceiling[i] == ',')
            {
                if (ceiling[i + 1] == ',')
                    return (write (2, "Error : wrong texture input\n", 29), 1);
                coma++;
            }
            i++;
        }
        else
            return (write (2, "Error : wrong texture input\n", 29), 1);
    }
    if (coma != 2 || ceiling[i - 1] == ',')
        return (write (2, "Error : wrong texture input\n", 28), 1);
    return (0);
}

int check_texture(t_vars **vars)
{
    if (init_texture_info(vars) == 1)
        return (1);
    if (check_floor_info((*vars)->floor_info))
        return (1);
    if (check_ceiling_info((*vars)->ceiling_info))
        return (1);
    return (0);
}

int parsing(t_vars **vars, char **av)
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
    if (check_args(av[1]) == 1) //a revoir pour les droit de fichier si cela marche correctement
        return (1);
    if (check_texture(vars) == 1) //split sur les virgule pour check les nombre et apres fini
        return (1);
    return (0);
}