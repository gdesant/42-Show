/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

void	free_map(t_mapdata *map)
{
	int	i;

	i = -1;
	if (map != NULL)
	{
		if (map->init == TRUE)
		{
			if (map->maparray != NULL)
			{
				while (++i < map->height)
					free(map->maparray[i]);
				free(map->maparray);
			}
			if (map->col_pos != NULL)
				free (map->col_pos);
		}
	}
	return ;
}
