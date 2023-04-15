#include "cub3D.h"



//verifier si les espaces apres ou avant le path sont consideres
int check_texture(char  *string)
{
    int     fd;
    char    *cleanstring;
    
    cleanstring = ft_substr(string, 3, ft_strlen(string) - 3);
    // 
    // string = cleanstring;

    printf("string = .%s.\n", cleanstring);
    fd = open(cleanstring, O_RDONLY);
    free (cleanstring);
    if (fd < 0)
        return (printf("errortext1\n"), -1);
    else
        return(close(fd), 1);
}

/*verifier la si 000250 est acceptable -> est ce que 025 valable aussi?*/
int check_num(char *string, int *i, int type)
{
    int     j;
    char    *num;
    int     number;

    j = 0;
    while (ft_isdigit(string[*i]))
    {
        j++;
        *i += 1;
    }
    num = ft_substr(string, *i - j, j);
    number = ft_atoi(num);
        free(num);
    if (number < 0 || number > 255)
        return (printf("rgb2\n"), -1);
    if (type == 1)
    {
        if (string[*i] == ',')
        *i += 1;
        else
            return (printf("rgb3\n"), -1);
        // printf("string = %s / i = %d\n", string, *i);
        if (*i >= (int) ft_strlen(string))
            return (printf("rgb4\n"), -1);
        else
            return (1);
    }
    if (*i == (int) ft_strlen(string))
        return (1);
    else
        return (printf("rgb5\n"), -1);
}

int check_RGB(char *string)
{
    int     i;
    
    i = 1;
    while (string[i] == ' ')
        i++;
    if (i == 1 || !(ft_isdigit(string[i])))
        return (printf("rgb1\n"), -1);
    
    if (check_num(string, &i, 1) == -1)
        return (printf("firstrgb\n"),-1);
    if (check_num(string, &i, 1) == -1)
        return (printf("dozrgb\n"),-1);       
    if (check_num(string, &i, 2) == -1)
        return (printf("thirdrgb\n"),-1);  
    return (1);
}

int parse_data(t_map *map)
{
    if (check_RGB(map->C_input) == -1)
        return (-1);
    if (check_RGB(map->F_input) == -1)
        return (-1);
    if (check_texture(map->EA_input) == -1)
        return (-1);
    if (check_texture(map->WE_input) == -1)
        return (-1);
    if (check_texture(map->NO_input) == -1)
        return (-1);
    if (check_texture(map->SO_input) == -1)
        return (-1);
    
    return (1);
}

// F 220,100,0
// C 225,30,0 



 /*Resolution values that are bigger that the screens that we have in school 
 or non-digit numbers or more than 2 values (width and height)

Textures are a file that doesnt exist (open function would fail) or not a xpm file.

There are multiple textures for the same wall (north wall texture).*/