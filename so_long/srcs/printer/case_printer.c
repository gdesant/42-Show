/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_img	get_image(t_game *gm, t_vector2 block)
{
	int	c;

	c = is_valid_char(gm->map->maparray[block.y][block.x]);
	if (c == 1)
		return (gm->tex.wall);
	return (gm->tex.free);
}

unsigned int	get_pixel(t_img img, double ratio_x, double ratio_y)
{
	unsigned int	pix;
	t_vector2		imp;

	imp = create_vector2(0, 0);
	if (ratio_x >= 1)
		imp.x = img.size.x;
	else if (ratio_x > 0)
		imp.x = (int)(img.size.x * ratio_x);
	if (ratio_y >= 1)
		imp.y = img.size.y;
	else if (ratio_y > 0)
		imp.y = (int)(img.size.y * ratio_y);
	pix = img.mimg.data[imp.y * img.size.x + imp.x];
	return (pix);
}

int	print_case_pixel(t_game *gm, t_vector2 block, t_mlx_img *screen, t_img img)
{
	t_vector2		init;
	t_vector2		end;	
	t_vector2		start;

	start = create_vector2(block.x * gm->c_size.x, block.y * gm->c_size.y);
	end = create_vector2(start.x + gm->c_size.x, start.y + gm->c_size.y);
	init = start;
	while (start.y < end.y)
	{
		while (start.x < end.x)
		{
			put_pixel_to_img(screen, start.x, start.y, get_pixel(img,
					((double)(start.x - init.x) / gm->c_size.x),
					((double)(start.y - init.y) / gm->c_size.y)));
			start.x++;
		}
		start.x = init.x;
		start.y++;
	}
	return (FALSE);
}
