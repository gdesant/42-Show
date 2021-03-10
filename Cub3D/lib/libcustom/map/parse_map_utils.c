/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int		ismapline(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '2' && line[i]
			!= '1' && line[i] != '0')
			if (!(line[i] == 'N' || line[i] == 'W' ||
				line[i] == 'E' || line[i] == 'S'))
				return (0);
		i++;
	}
	return (1);
}

int		treatmapline(char *line, t_mapfile *mp)
{
	static int i;

	if (mp->map.lenght == 0)
		i = 0;
	else
		i++;
	if (ft_strlen(line) > mp->map.lenght)
		mp->map.lenght = ft_strlen(line);
	mp->map.maparray[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	ft_strlcpy(mp->map.maparray[i], line, ft_strlen(line) + 1);
	mp->map.c = i;
	return (1);
}

int		treatsrcline(char *line, t_mapfile *mp)
{
	int err;

	err = 0;
	if (*line == 'R')
		err = getresfile(line + 1, &mp->resolution);
	else if (*line == 'N' && line[1] == 'O')
		err = getsrcfile(line + 2, &mp->tex.no);
	else if (*line == 'S' && line[1] == 'O')
		err = getsrcfile(line + 2, &mp->tex.so);
	else if (*line == 'W' && line[1] == 'E')
		err = getsrcfile(line + 2, &mp->tex.we);
	else if (*line == 'E' && line[1] == 'A')
		err = getsrcfile(line + 2, &mp->tex.ea);
	else if (*line == 'S')
		err = getsrcfile(line + 2, &mp->tex.sprite);
	else if (*line == 'F')
		err = getcolorfile(line + 1, &mp->ground_color);
	else if (*line == 'C')
		err = getcolorfile(line + 1, &mp->roof_color);
	return (err);
}

int		get_map_height(int fd)
{
	int		i;
	int		res;
	char	*file;
	int		x;

	x = 0;
	i = 0;
	res = 1;
	file = NULL;
	while (res > 0)
	{
		res = get_map_lines(fd, &file);
		if (file == NULL && x == 1)
			x = -1;
		if (file != NULL && file[0] != 0 && res > -1)
			if (x >= 0 && ismapline(file))
			{
				if (x == 0)
					x = 1;
				i++;
			}
		if (file != NULL)
			free(file);
	}
	return (i);
}
