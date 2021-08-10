/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int	free_line_error(char **fil, int fd, t_vector2 pos)
{
	int		res;
	char	*file;

	file = *fil;
	res = 1;
	alert_char_issue(pos, MAP_ERR_FRLINE);
	free(file);
	while (res > 0)
	{
		res = get_next_line(fd, &file);
		if (file != NULL)
			free(file);
	}
	return (MAP_ERR_FRLINE);
}

int	invalid_char_error(char **fil, int fd, t_vector2 pos)
{
	int		res;
	char	*file;

	file = *fil;
	res = 1;
	alert_char_issue(create_vector2(pos.x, pos.y), MAP_ERR_INVALIDCHAR);
	free(file);
	while (res > 0)
	{
		res = get_next_line(fd, &file);
		if (file != NULL)
			free(file);
	}
	return (MAP_ERR_INVALIDCHAR);
}

int	check_for_invalid(char **fil, t_vector2 *plac, int fd)
{	
	char	*file;

	file = *fil;
	if (ft_strlen(file) > 0)
	{
		while (file[++plac->x] != 0)
			if (is_valid_char(file[plac->x]) == -1)
				return (invalid_char_error(&file, fd, *plac));
	}
	else
		return (free_line_error(&file, fd, *plac));
	free(file);
	plac->x = -1;
	plac->y++;
	return (FALSE);
}

int	precheck(char *path)
{
	int			res;
	int			fd;
	t_vector2	pos;
	char		*file;
	int			err;

	err = 0;
	res = 1;
	fd = open(path, O_RDONLY);
	pos.x = -1;
	pos.y = 0;
	while (res > 0 && err == FALSE)
	{
		res = get_next_line(fd, &file);
		err = check_for_invalid(&file, &pos, fd);
	}
	close(fd);
	if (err != FALSE)
		return (err);
	return (FALSE);
}
