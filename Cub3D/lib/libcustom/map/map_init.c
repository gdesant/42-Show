/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int		map_init(t_game *gm, char *path)
{
	int fd;
	int size;

	size = 0;
	fd = open(path, O_RDONLY);
	size = get_map_height(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	if (!parse_map(fd, gm, size))
	{
		free_map(gm->mf);
		return (0);
	}
	if (!check_map_error(gm->mf))
	{
		free_map(gm->mf);
		return (0);
	}
	close(fd);
	return (1);
}

void	initmp(t_mapfile *mp)
{
	mp->tex.no.path = NULL;
	mp->tex.so.path = NULL;
	mp->tex.ea.path = NULL;
	mp->tex.we.path = NULL;
	mp->tex.sprite.path = NULL;
	mp->map.maparray = NULL;
	mp->roof_color.s = 0;
	mp->map.c = -1;
	mp->map.e = 0;
	mp->ground_color.s = 0;
	mp->resolution.x = -1;
	mp->resolution.y = -1;
	mp->pl.set = 0;
	mp->map.lenght = 0;
	mp->map.height = 0;
	return ;
}
