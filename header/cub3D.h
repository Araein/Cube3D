/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:44:28 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/19 13:29:57 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

typedef struct s_map
{
    int     number_of_line;
    char    *NO_input;
    char    *SO_input;
    char    *WE_input;
    char    *EA_input;
    char    *F_input;
    char    *C_input;
    char    **map;
    int     player;
}				t_map;

typedef struct s_cub
{
    t_map   *map;

}				t_cub;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// # define FORWARD	119
// # define BACK		115
// # define LEFT		97
// # define RIGHT		100

// int	structinit(t_elem *cub);
int     main(int argc, char **argv);

//gnl_utils
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);

//gnl
int     get_next_line(int fd, char **line);

//free_data.c
void	free_map(t_map *map);
void    free_tab(char **tab);

//parse_data.c
int     parse_data(t_map *map);

//parse_map.c
int     parse_map(t_map *map);

//ft_itoa.c
// char	*ft_itoa(long long n);
int	    ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif