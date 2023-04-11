/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <tlebouvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:40:42 by tlebouvi          #+#    #+#             */
/*   Updated: 2023/04/11 17:42:06 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_map *map)
{
	if (map->NO_input)
    	free(map->NO_input);
	if (map->SO_input)
    	free(map->SO_input);
	if (map->WE_input)
    	free(map->WE_input);
	if (map->EA_input)
		free(map->EA_input);
	if (map->F_input)
		free(map->F_input);
	if (map->C_input)
		free(map->C_input);
}

void    free_tab(char **tab)
{
    int i;

    i = 0;
    if (tab)
    {
        while (tab[i])
        {
            free(tab[i]);
            i++;
        }
    }
    free(tab);
}