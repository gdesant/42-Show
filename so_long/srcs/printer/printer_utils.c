/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	put_pixel_to_img(t_mlx_img *img, int x, int y, unsigned int clr)
{
	if (clr != 16187883)
		img->data[(y * img->width) + x] = clr;
	return ;
}

int	getclr(t_color clr)
{
	int	rgb;

	rgb = clr.r;
	rgb = (rgb << 8) + clr.g;
	rgb = (rgb << 8) + clr.b;
	return (rgb);
}

t_color	create_color(int r, int g, int b, int s)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	col.s = s;
	return (col);
}

t_coll	create_coll(t_vector2 pos)
{
	t_coll	col;

	col.pos = pos;
	col.is_pick = FALSE;
	return (col);
}

void	print_coll(t_game *gm)
{	
	t_img	col;
	int		x;

	if (gm->tex.coll.actual_frame < gm->tex.coll.count - 1)
		gm->tex.coll.actual_frame++;
	else
		gm->tex.coll.actual_frame = 0;
	col = gm->tex.coll.imgs[gm->tex.coll.actual_frame];
	x = -1;
	while (++x < gm->pl.coll_amount)
		if (gm->colls[x].is_pick == FALSE)
			print_case_pixel(gm, gm->colls[x].pos, &gm->grid, col);
	return ;
}
