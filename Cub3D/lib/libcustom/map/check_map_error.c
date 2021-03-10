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

int	check_resolution(t_mapfile *map)
{
	if (map->resolution.x < 0 || map->resolution.y < 0)
	{
		ft_printf("Erreur : Résolution Négative !\n");
		return (1);
	}
	else if (map->resolution.x == 0 || map->resolution.y == 0)
	{
		ft_printf("Erreur : Resolution non définie !\n");
		return (1);
	}
	return (0);
}

int	check_img(t_img *img, char *id)
{
	char *temp;

	temp = NULL;
	if (img->path == NULL || ft_strlen(img->path) < 1
		|| ft_strlen_nspace(img->path) < 1)
	{
		ft_printf("Source |%s| vide !\n", id);
		return (1);
	}
	temp = img->path + (ft_strlen(img->path) - 4);
	if (ft_strncmp(temp, ".xpm", ft_strlen(temp)))
	{
		ft_printf("Source |%s| invalide :\n", id);
		ft_printf("Format d'image invalide : '%s'\n", temp);
		return (1);
	}
	if ((img->fd = open(img->path, O_RDONLY)) == -1)
	{
		ft_printf("Source |%s| erreur : '%s' !\n", id, img->path);
		return (1);
	}
	return (0);
}

int	check_map_colors(t_color *c, char *id)
{
	if (c->s != 1)
	{
		ft_printf("La couleur du | %s | n'est pas définie !\n", id);
		return (1);
	}
	if (c->r > 255 || c->r < 0)
	{
		ft_printf("La couleur rouge du | %s | est invalide!\n", id);
		return (1);
	}
	if (c->g > 255 || c->g < 0)
	{
		ft_printf("La couleur verte du | %s | est invalide!\n", id);
		return (1);
	}
	if (c->b > 255 || c->b < 0)
	{
		ft_printf("La couleur bleue du | %s | est invalide!\n", id);
		return (1);
	}
	return (0);
}

int	check_maparray(t_mapfile *mf)
{
	int y;
	int x;

	x = 0;
	y = 0;
	if (mf->map.c < 0)
		ft_printf("Aucune Map rentrée !\n");
	else if (mf->map.height < 3 || mf->map.lenght < 3)
		ft_printf("Map trop petite !\n");
	if (mf->map.height < 3 || mf->map.lenght < 3 || mf->map.c < 0)
		return (1);
	while (mf->map.maparray[y] && mf->map.height > y && y <= mf->map.c)
	{
		while (x < ft_strlen(mf->map.maparray[y]))
		{
			if (check_free_case(mf->map.maparray[y][x]) > 1)
				if (check_case(mf, x, y))
					return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
