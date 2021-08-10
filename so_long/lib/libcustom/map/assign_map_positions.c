/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_map_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int	add_position(t_mapdata *map, int col_c, char c)
{
	if (c == MAP_CL && col_c < map->col_amount)
	{
		map->col_pos[col_c] = map->err_pos;
		return (-2);
	}
	else if (c == MAP_PL)
	{
		if (!isnull_vector2(map->player_pos))
			return (MAP_ERR_TOO_P);
		map->player_pos = map->err_pos;
	}
	else if (c == MAP_EX)
	{
		if (!isnull_vector2(map->exit_pos))
			return (MAP_ERR_TOO_E);
		map->exit_pos = map->err_pos;
	}
	return (FALSE);
}

int	check_map_full(t_mapdata *map)
{
	if (map->err == FALSE)
	{
		if (map->col_pos == NULL || map->col_amount <= 0)
			map->err = MAP_ERR_MISSING_C;
		if (isnull_vector2(map->player_pos))
			map->err = MAP_ERR_MISSING_P;
		if (isnull_vector2(map->exit_pos))
			map->err = MAP_ERR_MISSING_E;
		if (map->err == 0)
			return (FALSE);
	}
	return (TRUE);
}

int	check_map_index(t_mapdata *map, int col_c)
{
	char	c;
	int		err;
	int		x;
	int		y;

	x = map->err_pos.x;
	y = map->err_pos.y;
	c = map->maparray[y][x];
	err = is_valid_char(c);
	if (err == -1)
		return (MAP_ERR_INVALIDCHAR);
	if ((x == 0 || x == map->lenght - 1) || (y == 0 || y == map->height - 1))
	{
		if (err != 1)
		{
			map->err_pos = create_vector2(x, y);
			return (MAP_ERR_OPEN);
		}
	}
	if (err >= 2)
		return (add_position(map, col_c, c));
	return (0);
}

int	assign_map_positions(t_mapdata *map)
{
	t_vector2	pos;
	int			col_c;

	pos = create_vector2(-1, -1);
	map->col_pos = malloc(sizeof(t_vector2) * map->col_amount + 1);
	if (map->col_pos == NULL)
		return (TRUE);
	col_c = 0;
	while (++pos.y < map->height && map->err <= 0)
	{
		while (map->maparray[pos.y][++pos.x])
		{
			map->err_pos = create_vector2(pos.x, pos.y);
			map->err = check_map_index(map, col_c);
			if (map->err > FALSE)
				return (check_map_full(map));
			else if (map->err == -2)
				col_c++;
		}
		pos.x = -1;
		map->err = 0;
	}
	return (check_map_full(map));
}
