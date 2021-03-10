/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_wall(t_game *gm, t_wall wall)
{
	int count;
	int y;

	y = 0;
	if (wall.starty < 0)
	{
		y = wall.starty * -1;
		count = y + gm->mf->resolution.y;
	}
	else
		count = wall.height;
	while (y < count && wall.starty + y < gm->mf->resolution.y)
	{
		put_pixel_to_img(&gm->screen, wall.startx, wall.starty + y,
			ray_side(gm, wall.i, (double)y / wall.height));
		y++;
	}
}

int		drawskyfloor(t_game *gm)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < gm->mf->resolution.y / 2)
	{
		while (x <= gm->mf->resolution.x)
			put_pixel_to_img(&gm->screen, x++, y,
				getclr(gm->mf->roof_color));
		x = 0;
		y++;
	}
	while (y <= gm->mf->resolution.y)
	{
		while (x <= gm->mf->resolution.x)
			put_pixel_to_img(&gm->screen, x++, y,
				getclr(gm->mf->ground_color));
		x = 0;
		y++;
	}
	return (1);
}

int		draw_walls(t_game *gm)
{
	t_wall	wall;
	int		i;
	float	dist;

	i = 0;
	dist = 0.0;
	if (!drawskyfloor(gm))
		return (0);
	while (i < gm->mf->resolution.x)
	{
		if (gm->ray_array[i].endx != -1 && gm->ray_array[i].endy != -1)
		{
			wall.dist = hypot((gm->pl.x - gm->ray_array[i].endx),
				(gm->pl.y - gm->ray_array[i].endy));
			wall.dist *= cos(gm->ray_array[i].ang);
			wall.lenght = gm->mf->resolution.x / gm->mf->resolution.x;
			wall.height = (gm->mf->resolution.y * 0.99) / wall.dist;
			wall.startx = i;
			wall.starty = (gm->mf->resolution.y / 2) - (wall.height / 2);
			wall.i = i;
			draw_wall(gm, wall);
		}
		i++;
	}
	return (1);
}
