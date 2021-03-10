/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ho_check(t_game *gm, int x, double *tempx, double *tempy)
{
	if (gm->ray_array[x].roty >= 0)
		gm->ray_array[x].h = 1;
	else
		gm->ray_array[x].h = 0;
	*tempy = floor(gm->ray_array[x].posy) + gm->ray_array[x].h;
	*tempx = gm->ray_array[x].posx + (*tempy - gm->ray_array[x].posy) *
	(gm->ray_array[x].rotx / gm->ray_array[x].roty);
	return (gm->ray_array[x].h);
}

int		vo_check(t_game *gm, int x, double *tempx, double *tempy)
{
	if (gm->ray_array[x].rotx >= 0)
		gm->ray_array[x].v = 1;
	else
		gm->ray_array[x].v = 0;
	*tempx = floor(gm->ray_array[x].posx) + gm->ray_array[x].v;
	*tempy = gm->ray_array[x].posy + (*tempx - gm->ray_array[x].posx) *
	(gm->ray_array[x].roty / gm->ray_array[x].rotx);
	return (gm->ray_array[x].v);
}

double	alwayspos(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
