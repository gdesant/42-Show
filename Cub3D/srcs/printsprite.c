/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	sprite_pixel(t_game *gm, int i, unsigned int col)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (col == 0xf701eb)
		return (gm->screen.data[i]);
	else if (col < 256 * 256 * 256)
		return (col);
	t = col / (256 * 256 * 256);
	r = (col / (256 * 256) % 256) * (1 - (double)t / 256);
	g = (col / 256 % 256) * (1 - (double)t / 256);
	b = (col % 256) * (1 - (double)t / 256);
	r += (gm->screen.data[i] / (256 * 256) % 256) * ((double)t / 256);
	g += (gm->screen.data[i] / 256 % 256) * ((double)t / 256);
	b += (gm->screen.data[i] % 256) * ((double)t / 256);
	return (r * 256 * 256 + g * 256 + b);
}

void			sprite_draw(t_game *gm, int loc, double d)
{
	unsigned int	col;
	double			size;
	int				index;
	int				i;
	int				j;

	i = 0;
	j = 0;
	size = gm->mf->resolution.y / d / 2;
	loc = loc - size / 2;
	while (i < size)
	{
		while ((loc + i >= 0 && loc + i < gm->mf->resolution.x) &&
				(j < size && gm->ray_array[loc + i].d > d))
		{
			col = 64 * floor(64 * (double)j / size) + (double)i / size * 64;
			col = gm->mf->tex.sprite.mimg.data[col];
			index = loc + i +
			(gm->mf->resolution.y / 2 + j++) * gm->mf->resolution.x;
			if (index < gm->mf->resolution.x * gm->mf->resolution.y)
				gm->screen.data[index] = sprite_pixel(gm, index, col);
		}
		i++;
		j = 0;
	}
}

void			spot_sprites(t_game *gm, double x, double y, double d)
{
	double	angle;

	x = (x - gm->pl.x) / d;
	y = (y - gm->pl.y) / d;
	if (y <= 0)
		angle = acos(x) * 180 / M_PI;
	else
		angle = 360 - acos(x) * 180 / M_PI;
	angle = gm->pl.ang - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	sprite_draw(gm, angle * gm->mf->resolution.x / 66, d);
}

void			sprites_action(t_game *gm)
{
	t_sprite		tmp;
	int				i;
	int				j;

	i = 0;
	while (i < gm->spritelen - 1)
	{
		j = i + 1;
		while (j < gm->spritelen)
		{
			if (gm->sprites[i].d < gm->sprites[j].d)
			{
				tmp = gm->sprites[i];
				gm->sprites[i] = gm->sprites[j];
				gm->sprites[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			print_sprites(t_game *gm)
{
	int		i;
	double	d;

	d = hypot(gm->pl.rotx, gm->pl.roty);
	i = 0;
	if (gm->pl.roty <= 0)
		gm->pl.ang = acos(gm->pl.rotx / d) * 180 / M_PI;
	else
		gm->pl.ang = 360 -
			acos(gm->pl.rotx / d) * 180 / M_PI;
	while (i < gm->spritelen)
	{
		gm->sprites[i].d = hypot(gm->sprites[i].pos.x -
			gm->pl.x, gm->sprites[i].pos.y - gm->pl.y);
		i++;
	}
	sprites_action(gm);
	i = 0;
	while (i < gm->spritelen)
	{
		spot_sprites(gm, gm->sprites[i].pos.x, gm->sprites[i].pos.y,
			gm->sprites[i].d);
		i++;
	}
	return ;
}
