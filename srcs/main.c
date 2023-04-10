/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:45:33 by tlebouvi          #+#    #+#             */
/*   Updated: 2023/04/10 16:15:07 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


// int	error(int type, t_elem *elem)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	if (type == 0)
// 		ft_putstr_fd("Something went wrong with your input\n", 2);
// 	if (type == 1)
// 	{
// 		freetab(elem->map, elem);
// 		ft_putstr_fd("Your map doesn't fit\n", 2);
// 	}
// 	if (type == 2)
// 	{	
// 		if (elem->error == 3)
// 			ft_putstr_fd("The map is too big for your screen\n", 2);
// 		else if (elem->error == 4)
// 			ft_putstr_fd("Something is wrong with your .xpm files\n", 2);
// 		else
// 			ft_putstr_fd("Window initialization failed\n", 2);
// 	}
// 	if (type == 3)
// 		ft_putstr_fd("Something went wrong with the memory allocation\n", 2);
// 	return (0);
// }



// int	createmap(char **argv, t_elem *elem, int fd)
// {
// 	int	d;

// 	d = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	elem->map = malloc (sizeof(char *) * (elem->mapsize + 1));
// 	if (elem->map == NULL)
// 		return (0);
// 	while (get_next_line(fd, &(elem->temp)) > 0)
// 	{
// 		elem->map[d] = ft_strdup(elem->temp);
// 		free(elem->temp);
// 		d++;
// 	}
// 	close(fd);
// 	if (elem->temp)
// 	{
// 		elem->map[d] = ft_strdup(elem->temp);
// 		free(elem->temp);
// 		if (elem->map[d] == NULL)
// 			return (0);
// 	}
// 	elem->map[d + 1] = NULL;
// 	return (1);
// }

// int	writemap(char **argv, int fd, t_elem *elem)
// {
// 	close(fd);
// 	fd = open(argv[1], O_RDONLY);
// 	while (get_next_line(fd, &(elem->temp)))
// 	{
// 		elem->mapsize++;
// 		free(elem->temp);
// 	}
// 	if (elem->temp)
// 	{
// 		elem->mapsize++;
// 		free(elem->temp);
// 	}
// 	elem->clean = elem->mapsize;
// 	close(fd);
// 	if (createmap(argv, elem, fd) == 0)
// 		return (0);
// 	return (1);
// }

// void	structinit(t_elem *elem)
// {
// 	elem->map = NULL;
// 	elem->mapsize = 0;
// 	elem->maplen = 0;
// 	elem->counte = 0;
// 	elem->countc = 0;
// 	elem->countp = 0;
// 	elem->temp = NULL;
// 	elem->x = 0;
// 	elem->y = 0;
// 	elem->count = 0;
// 	elem->playermove = 0;
// 	elem->duo = 0;
// 	elem->clean = 0;
// 	elem->error = 0;
// }

int	all_data_here(t_map *map)
{
    if(!NO_input)
		return (-1);
    if(!SO_input)
		return (-1);
    if(!WE_input)
		return (-1);
    if(!EA_input)
		return (-1);
    if(!F_input)
		return (-1);
    if(!C_input)
		return (-1);
	return (1)
}

int	check_first_char(char	*string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '1' && string[i] == '\n')
			return (1);		
		if (string[i] != ' ') // attention pas de saut de ligne pdt la map
			return (0);
		i++;
	}
	return (1);
}

void	init_map_struct(t_map *map)
{
    number_of_line = 0;
    NO_input = NULL;
    SO_input = NULL;
    WE_input = NULL;
    EA_input = NULL;
    F_input = NULL;
    C_input = NULL;	
}

int	check_map(char *string, t_map *map)
{
	int	fd;
	// char	**map;
	char	*line;

	init_map_struct(map);
	fd = open(string, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		//ignorer les sauts de ligne//
		if (!(ft_strlen(line) = 1 && line[0] = '\n'))
		{
			if (ft_strlen(line) > 2 && line[0] = 'N' && line[1] = 'O' && line[2] = ' ')
			{
				
			}
			else if (ft_strlen(line) > 2 && line[0] = 'S' && line[1] = 'O' && line[2] = ' ')
			{
				
			}
			else if (ft_strlen(line) > 2 && line[0] = 'W' && line[1] = 'E' && line[2] = ' ')
			{
				
			}
			else if (ft_strlen(line) > 2 && line[0] = 'E' && line[1] = 'A' && line[2] = ' ')
			{
				
			}
			else if (ft_strlen(line) > 1 && line[0] = 'F'  && line[1] = ' ')
			{
				
			}
			else if (ft_strlen(line) > 1 && line[0] = 'C' && line[1] = ' ')
			{
				
			}
			else if (check_first_char(line) && all_data_here(map)) //on est a la map + on a toutes les infos
			{
				
			}
			else
			{
				free(line);
				line = NULL;
				return (-1);		
			}
		}
		else
		{
			free(line);
			line = NULL;
		}
		map->number_of_line += 1;
		/*
		regarder les deux premiers charac des lignes
		si 1 = \n -> pass
		si NO SO WE EA F C



		*/

	/*que faire si un meme element est defini plusieurs fois?*/
	}
	free (line);
	line = NULL;
	close(fd);
	
	printf("line num = %d", map->number_of_line);
/*

ligne commence forcement par un identifiant


Soit ca commence par un identifiant soit 1 ou ' ' -> puis 1 

pas de lignes vides dans la map

◦ Pour chaque élement, le premier caractère est l’identifiant (un ou deux carac-
tères), suivi de toutes les informations spécifiques à l’élément dans un ordre
strict tel que :
— texture nord :
NO ./path_to_the_north_texture
— identifiant : NO
— chemin vers la texture nord
— South texture :
SO ./path_to_the_south_texture
— identifiant : SO
— chemin vers la texture sud
— West texture :
WE ./path_to_the_west_texture
— identifiant : WE
— chemin vers la texture ouest
— East texture :
EA ./path_to_the_east_texture
— identifiant : EA
— chemin vers la texture est
— Couleur du sol :
F 220,100,0
— identifiant : F
— couleurs R,G,B range [0,255] : 0, 255, 255
— Couleur du plafond :
C 225,30,0
— identifiant : C
— couleurs R,G,B range [0,255] : 0, 255, 255
*/
	//verifier si elle est fermee
	//verifiee si il y a les bons charac
	return (1);
}

int	check_arg(char **argv, int argc)
{
	char	*check_cub;
	int		i;
	int		len;

	len = ft_strlen(argv[1]);
	i = 3;
	check_cub = ".cub";
	if (argc != 2)
		return (-1);
	if (len < 5)
		return (-1);
	while(i >= 0)
	{
		if (check_cub[i] != argv[1][len - 1])
			break ;
		len--;
		i--;
	}
	if (i >= 0)
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	// t_map	*map;

	cub.map = (t_map *)malloc(sizeof(t_map));
	cub.map->number_of_line = 0;
	// cub.map = malloc(sizeof(t_map*));
	// cub.map = map;
//	t_elem	elem;
//	int		fd;

	if (check_arg(argv, argc) == -1)
		return (free(cub.map), write(2, "Error\nWrong input\n", 18), -1);
	if (check_map(argv[1], cub.map) == -1)
	 	return (free(cub.map), write(2, "Error\nIssue within the .cub file\n", 33), -1);
	
	// structinit(&elem);
	// if (!(parsing(argc, argv, &elem)))
	// 	return (error(0, &elem));
	// fd = open(argv[1], O_RDONLY);
	// if (get_next_line(fd, &(elem.temp)) == -1)
	// 	return (mainerror(&elem));
	// if (elem.temp)
	// 	free(elem.temp);
	// if (writemap(argv, fd, &elem) == 0)
	// {
	// 	freetab(elem.map, &elem);
	// 	return (error(3, &elem));
	// }
	// if (elem.mapsize < 3 || !(checkmap(&elem)))
	// 	return (error(1, &elem));
	// if (!(windowinit(&elem)))
	// 	return (error(2, &elem));
	return (1);
}
