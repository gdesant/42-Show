/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

t_mapdata	initmp(t_vector2 *size)
{
	t_mapdata	mp;

	mp.lenght = (int)size->x;
	mp.height = (int)size->y;
	mp.maparray = (char **)malloc(sizeof(char *) * mp.height + 1);
	mp.maparray[mp.height] = NULL;
	mp.err = 0;
	mp.err_pos = create_vector2(-1, -1);
	mp.player_pos = create_vector2(-1, -1);
	mp.exit_pos = create_vector2(-1, -1);
	mp.col_pos = NULL;
	mp.col_amount = 0;
	mp.init = TRUE;
	free(size);
	return (mp);
}

int	acquire_map(t_mapdata *md, t_vector2 *size, char *path)
{
	int			res;
	int			fd;
	char		*file;
	t_vector2	pos;

	pos = create_vector2(-1, -1);
	res = 1;
	fd = open(path, O_RDONLY);
	*md = initmp(size);
	while (res > 0)
	{
		res = get_next_line(fd, &file);
		if (ft_strlen(file) > 0)
		{
			md->maparray[++pos.y] = ft_strdup(file);
			free(file);
			while (md->maparray[pos.y][++pos.x])
				if (md->maparray[pos.y][pos.x] == MAP_CL)
					md->col_amount++;
			pos.x = -1;
		}
		else
			free(file);
	}
	return (FALSE);
}
