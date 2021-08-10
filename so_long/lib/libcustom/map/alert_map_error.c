/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alert_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int	alert_map_issue(int err)
{
	if (err == MAP_ERR_INVALID)
		printf("Error %d : Invalid Map File !\n", err);
	else if (err == MAP_ERR_OPEN)
		printf("Error %d : Your map is Open !\n", err);
	else if (err == MAP_ERR_NOTSQUARE)
		printf("Error %d : The Map is not a Rectangle !\n", err);
	else if (err == MAP_TOO_SMALL)
		printf("Error %d : %s {x:%d, y:%d}\n", err,
			"The Map is too small ! Min Required Size :",
			MIN_MAP_LEN, MIN_MAP_HEI);
	return (err);
}

int	alert_char_issue(t_vector2 pos, int err)
{
	if (err == MAP_ERR_INVALIDCHAR)
		printf("Error %d : Invalid Character at pos {x:%d, y:%d} !\n",
			err, (int)pos.x + 1, (int)pos.y + 1);
	else if (err == MAP_ERR_MISSING_P)
		printf("Error %d : Missing Player Position !\n", err);
	else if (err == MAP_ERR_MISSING_E)
		printf("Error %d : Missing Exit Position !\n", err);
	else if (err == MAP_ERR_MISSING_C)
		printf("Error %d : Missing Collectible Position !\n", err);
	else if (err == MAP_ERR_TOO_E)
		printf("Error %d : Second Exit at pos {x:%d, y:%d} !\n", err,
			(int)pos.x + 1, (int)pos.y + 1);
	else if (err == MAP_ERR_TOO_P)
		printf("Error %d : Second Player at pos {x:%d, y:%d} !\n", err,
			(int)pos.x + 1, (int)pos.y + 1);
	else if (err == MAP_ERR_FRLINE)
		printf("Error %d : The line %d is empty !\n", err,
			(int)pos.y + 1);
	return (err);
}

int	alert_map_error(t_mapdata *map)
{
	int	err;

	err = FALSE;
	if (map->init == TRUE)
	{
		if (map->err > 0 && map->err <= 4)
			err = alert_map_issue(map->err);
		else if (map->err >= 5 && map->err <= 10)
			err = alert_char_issue(map->err_pos, map->err);
		else if (map->err > 0)
			printf("Uknown Error %d !\n", err);
	}
	if (err != FALSE)
		free_map(map);
	return (err);
}
