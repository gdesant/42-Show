/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int				check_horizon(t_game *gm, int x, double vdist)
{
	double	tempx;
	double	tempy;
	int		h;

	h = ho_check(gm, x, &tempx, &tempy);
	while (tempx > 0 && tempx < ft_strlen(gm->mf->map.maparray[(int)tempy]))
	{
		if (hypot(tempy - gm->ray_array[x].posy, tempx -
			gm->ray_array[x].posx) >= vdist)
			return (1);
		if (gm->mf->map.maparray[(int)floor(tempy - 1 +
			h)][(int)floor(tempx)] != '1')
		{
			tempx += (2 * h - 1) * gm->ray_array[x].rotx /
			gm->ray_array[x].roty;
			tempy += (2 * h - 1);
		}
		else
		{
			gm->ray_array[x].endx = tempx;
			gm->ray_array[x].endy = tempy;
			return (1);
		}
	}
	return (0);
}

int				check_vertical(t_game *gm, int x)
{
	double	tempx;
	double	tempy;
	int		v;

	v = vo_check(gm, x, &tempx, &tempy);
	while (tempy > 0 && tempy < gm->mf->map.height)
	{
		if (gm->mf->map.maparray[(int)floor(tempy)][(int)floor(tempx -
		1 + v)] != '1')
		{
			tempy += (2 * v - 1) * gm->ray_array[x].roty /
			gm->ray_array[x].rotx;
			tempx += (2 * v - 1);
		}
		else
		{
			gm->ray_array[x].endx = tempx;
			gm->ray_array[x].endy = tempy;
			check_horizon(gm, x, hypot(tempx - gm->ray_array[x].posx,
			tempy - gm->ray_array[x].posy));
			return (1);
		}
	}
	gm->ray_array[x].endy = -1;
	return (check_horizon(gm, x, 10000));
}

int				init_rays(t_game *gm)
{
	int i;

	gm->ray_array = NULL;
	gm->ray_array = malloc(sizeof(t_ray) * gm->mf->resolution.x);
	i = 0;
	while (i < gm->mf->resolution.x)
	{
		gm->ray_array[i].ang = ((double)i - (gm->mf->resolution.x / 2)) * 33 /
		(gm->mf->resolution.x / 2);
		gm->ray_array[i].ang = gm->ray_array[i].ang * M_PI / 180;
		i++;
	}
	return (1);
}

int				raycast(t_game *gm)
{
	int		i;
	double	d;

	i = 0;
	while (i < gm->mf->resolution.x)
	{
		gm->ray_array[i].posx = gm->pl.x;
		gm->ray_array[i].posy = gm->pl.y;
		gm->ray_array[i].rotx = gm->pl.rotx * cos(gm->ray_array[i].ang) -
		gm->pl.roty * sin(gm->ray_array[i].ang);
		gm->ray_array[i].roty = gm->pl.roty * cos(gm->ray_array[i].ang) +
		gm->pl.rotx * sin(gm->ray_array[i].ang);
		d = hypot(gm->ray_array[i].rotx, gm->ray_array[i].roty);
		gm->ray_array[i].rotx /= d;
		gm->ray_array[i].roty /= d;
		check_vertical(gm, i);
		gm->ray_array[i].d = hypot(gm->ray_array[i].endx - gm->pl.x,
			gm->ray_array[i].endy - gm->pl.y);
		i++;
	}
	return (1);
}

unsigned int	ray_side(t_game *gm, int i, double x)
{
	int	index;

	if (floor(gm->ray_array[i].endy) == gm->ray_array[i].endy)
	{
		index = 64 * floor(64 * alwayspos(gm->ray_array[i].h - x)) + 64 *
		(gm->ray_array[i].endx - floor(gm->ray_array[i].endx));
		if (gm->ray_array[i].h == 1)
			return (gm->mf->tex.no.mimg.data[index]);
		else if (gm->ray_array[i].h == 0)
			return (gm->mf->tex.so.mimg.data[index]);
	}
	else if (floor(gm->ray_array[i].endx) == gm->ray_array[i].endx)
	{
		index = 64 * floor(64 * alwayspos(x)) + 64 *
		alwayspos(1 - (gm->ray_array[i].endy - floor(gm->ray_array[i].endy)));
		if (gm->ray_array[i].v == 1)
			return (gm->mf->tex.we.mimg.data[index]);
		else if (gm->ray_array[i].v == 0)
			return (gm->mf->tex.ea.mimg.data[index]);
	}
	return (0);
}
