/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int	check_free_case(char c)
{
	if (c == '1')
		return (1);
	else if (c == '0' || c == '2')
		return (2);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (3);
	return (0);
}

int	check_player_case(t_mapfile *mf, int x, int y)
{
	if (mf->pl.set == 1)
		return (1);
	mf->pl.x = x;
	mf->pl.y = y;
	mf->pl.set = 1;
	return (0);
}

int	check_utils(t_mapfile *mf, int x, int y)
{
	int err;

	err = 0;
	if (ft_strlen(mf->map.maparray[y - 1]) > x ||
	ft_strlen(mf->map.maparray[y + 1]) > x)
	{
		if (check_free_case(mf->map.maparray[y - 1][x]) == 0 ||
		check_free_case(mf->map.maparray[y + 1][x]) == 0)
			err = 1;
		if (check_free_case(mf->map.maparray[y][x - 1]) == 0 ||
			check_free_case(mf->map.maparray[y][x + 1]) == 0)
			err = 1;
	}
	else
	{
		err = 1;
	}
	if (check_free_case(mf->map.maparray[y][x]) == 3)
		if (check_player_case(mf, x, y) != 0)
			err = 2;
	return (err);
}

int	check_case(t_mapfile *mf, int x, int y)
{
	int len;
	int err;

	len = ft_strlen(mf->map.maparray[y]);
	err = 0;
	if (x == 0 || y == 0 || x == len || y == mf->map.height - 1)
		err = 1;
	else
		err = check_utils(mf, x, y);
	if (err == 1)
		ft_printf("Map ouvert en x:%d, y:%d!\n", x + 1, y + 1);
	if (err == 2)
		ft_printf("%s x:%d, y:%d!\n",
			"Erreur, deuxième position au niveau de la case:", x + 1, y + 1);
	if (err > 0)
		return (1);
	else
		return (0);
}

int	check_map_error(t_mapfile *map)
{
	if (check_resolution(map))
		return (0);
	if (check_img(&map->tex.no, "North"))
		return (0);
	if (check_img(&map->tex.so, "South"))
		return (0);
	if (check_img(&map->tex.we, "West"))
		return (0);
	if (check_img(&map->tex.ea, "East"))
		return (0);
	if (check_img(&map->tex.sprite, "Sprite"))
		return (0);
	if (check_map_colors(&map->roof_color, "Toit"))
		return (0);
	if (check_map_colors(&map->ground_color, "Sol"))
		return (0);
	if (check_maparray(map))
		return (0);
	if (map->pl.set != 1)
	{
		ft_printf("Pas de joueur sur la map !\n");
		return (0);
	}
	return (1);
}
