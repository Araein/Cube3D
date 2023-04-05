/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:44:28 by tlebouvi          #+#    #+#             */
/*   Updated: 2022/08/19 13:29:57 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

typedef struct s_cub
{

}				t_cub;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define ROCK "./images/ROCK0.xpm"
# define ROCK1 "./images/ROCK1.xpm"
# define ROCK2 "./images/ROCK2.xpm"
# define BABA "./images/baba0.xpm"
# define BABA1 "./images/baba1.xpm"
# define BABA2 "./images/baba2.xpm"
# define DOOR "./images/DOOR0.xpm"
# define DOOR1 "./images/DOOR1.xpm"
# define DOOR2 "./images/DOOR2.xpm"
# define KEY "./images/KEY0.xpm"
# define KEY1 "./images/KEY1.xpm"
# define KEY2 "./images/KEY2.xpm"
# define FORWARD	119
# define BACK		115
# define LEFT		97
# define RIGHT		100

//gnl

int	structinit(t_elem *cub);
// int		writemap(char **argv, int fd, t_elem *elem);
// int		createmap(char **argv, t_elem *elem, int fd);

#endif