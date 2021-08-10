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

int	map_init(t_game *gm, char *path)
{
	t_vector2	*size;
	t_mapdata	*md;
	int			err;

	err = 0;
	size = NULL;
	md = (t_mapdata *)malloc(sizeof(t_mapdata));
	md->init = FALSE;
	err = check_map_error(md, size, path);
	if (err == FALSE)
		gm->map = md;
	else
	{
		alert_map_error(md);
		if (md != NULL)
			free(md);
	}
	return (err);
}

int	is_valid_char(char c)
{
	if (c == MAP_FR)
		return (0);
	else if (c == MAP_WL)
		return (1);
	else if (c == MAP_CL)
		return (2);
	else if (c == MAP_PL)
		return (3);
	else if (c == MAP_EX)
		return (4);
	return (-1);
}
