/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int	get_line_size(t_vector2 *size, char *file, int *o_lenght, int fd)
{
	size->x = ft_strlen(file);
	if (file != NULL)
		free(file);
	if (size->x > 0 && size->y > 0 && size->x != *o_lenght)
	{
		while (get_next_line(fd, &file) > 0)
			free(file);
		free(file);
		return (MAP_ERR_NOTSQUARE);
	}
	*o_lenght = size->x;
	size->y++;
	return (FALSE);
}

int	get_map_size(t_vector2 *size, char *path)
{
	int		res;
	int		o_lenght;
	int		fd;
	char	*file;
	int		err;

	res = 1;
	o_lenght = 0;
	err = 0;
	fd = open(path, O_RDONLY);
	while (res > 0)
	{
		res = get_next_line(fd, &file);
		if (ft_strlen(file) > 0)
		{
			err = get_line_size(size, file, &o_lenght, fd);
			if (err != 0)
				return (err);
		}
		else
			free(file);
	}
	close(fd);
	return (FALSE);
}

int	check_map_first(t_vector2 *size, int *er, char *path)
{
	int	err;

	err = *er;
	err = precheck(path);
	if (err != 0)
	{
		free(size);
		return (MAP_ERR_INVALIDCHAR);
	}
	err = get_map_size(size, path);
	if (err == FALSE && (size->x < MIN_MAP_LEN || size->y < MIN_MAP_HEI))
		err = MAP_TOO_SMALL;
	if (err > 0)
	{
		alert_map_issue(err);
		free(size);
		return (err);
	}
	return (FALSE);
}

int	check_map_error(t_mapdata *md, t_vector2 *size, char *path)
{
	int	err;

	size = (t_vector2 *)malloc(sizeof(t_vector2));
	size->x = 0;
	size->y = 0;
	err = check_map_first(size, &err, path);
	if (err != 0)
		return (err);
	err = acquire_map(md, size, path);
	if (err > 0)
		return (err);
	if (md->col_amount <= 0)
	{
		md->err = MAP_ERR_MISSING_C;
		return (md->err);
	}
	if (assign_map_positions(md))
		return (md->err);
	return (FALSE);
}
