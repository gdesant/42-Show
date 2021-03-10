/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_pixel_to_img(t_mlx_img *img, int x, int y, int clr)
{
	if (x <= img->width && y <= img->height && y >= 0 && x >= 0)
		img->data[(y * img->width) + x] = clr;
	return ;
}

int		fixang(int a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

int		getclr(t_color clr)
{
	int rgb;

	rgb = clr.r;
	rgb = (rgb << 8) + clr.g;
	rgb = (rgb << 8) + clr.b;
	return (rgb);
}

int		count_case(t_game *gm, char c)
{
	int x;
	int y;
	int count;

	count = 0;
	x = 0;
	y = 0;
	while (y < gm->mf->map.height)
	{
		while (x < ft_strlen(gm->mf->map.maparray[y]))
		{
			if (gm->mf->map.maparray[y][x] == c)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

int		init_ang(t_game *gm)
{
	if (gm->mf->map.maparray[(int)gm->pl.y][(int)gm->pl.x] == 'N')
		return (90);
	if (gm->mf->map.maparray[(int)gm->pl.y][(int)gm->pl.x] == 'E')
		return (0);
	if (gm->mf->map.maparray[(int)gm->pl.y][(int)gm->pl.x] == 'S')
		return (-90);
	else
		return (180);
}
