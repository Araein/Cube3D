#include "cub3D.h"

int check_char(char c, t_map *map, int type)
{
    if (type == 1)
    {
        if ((c == 'W' || c == 'E' || c == 'S' || c == 'N') && map->player == 0)
        {
            map->player = 1;
            return (1);
        }
        if (c == ' ' || c == '0' || c == '1')
            return (1);
    }
    else if (type == 2)
        if (c == ' ' || c == '1')
            return (1);
    return (-1);
}

int check_inner_wall(t_map *map, int i, int j)
{
    if((i == 0 || !(map->map[i + 1])) && !(map->map[i][j] == ' '))
    {
        if (check_char(map->map[i][j], map, 2) == -1)
            return (-1);
    }
    else
    {
        if (j != 0)
            if (check_char(map->map[i][j - 1], map, 2) == -1)
                return (printf("1c\n"), -1);
        
        if (j != (int)(ft_strlen(map->map[i]) - 1))
            if (check_char(map->map[i][j + 1], map, 2) == -1)
                return (printf("2c\n"), -1);

        if (i != 0)
            if (check_char(map->map[i - 1][j], map, 2) == -1)
                 return (printf("3c\n"), -1);
        
        if (map->map[i + 1] && i != map->number_of_line - 1 && j < (int)(ft_strlen(map->map[i]) - (ft_strlen(map->map[i]) - ft_strlen(map->map[i + 1]))))
            if (check_char(map->map[i + 1][j], map, 2) == -1)
                return (printf("4c\n"), -1);
    }
    return (1);
}

int check_wall(t_map *map)
{
    int i;
    int j;
    int diff;

    diff = 0;
    i = 0;
    j = 0;
    while(map->map[i])
    {
        while(map->map[i][j])
        {
            if ((j == 0 || j == (int)(ft_strlen(map->map[i]) -  1)) && check_char(map->map[i][j], map, 2) == -1)
                return (printf("1\n"), -1);
            if (i > 0)
                diff = ft_strlen(map->map[i]) - ft_strlen(map->map[i - 1]);
            if (diff > 0 && j >= (int)(ft_strlen(map->map[i]) - diff)) 
            {
                if (check_char(map->map[i][j], map, 2) == -1)
                    return (printf("2\n"), -1);
            }
            else if (diff < 0) 
            {
                while (diff < 0)
                {
                    if (check_char(map->map[i - 1][ft_strlen(map->map[i - 1]) + diff], map, 2) == -1)
                        return (printf("3\n"), -1);
                    diff++;
                }
            }
            else
            {
                if (map->map[i][j] == ' ' || (i == 0 || !(map->map[i + 1])))//
                    if (check_inner_wall(map, i, j) == -1)
                        return (printf("4\n"), -1);
            }
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int parse_map(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map->map[i])
    {
        while(map->map[i][j])
        {
            if (check_char(map->map[i][j], map, 1) == -1)
                return (-1);
            j++;
        }
        i++;
        j = 0;
    }
    if (map->player == 0)
        return (printf("5\n"), -1);
    return (check_wall(map));
}
