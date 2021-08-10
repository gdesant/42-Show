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

#include "../include/so_long.h"

void	rescheck(t_game *gm, int sizex, int sizey)
{
	if (gm->resolution.x > sizex)
	{
		gm->resolution.x = sizex - (sizex % gm->map->lenght);
		gm->c_size.x = (int)(sizex / gm->map->lenght);
	}
	else
	{
		gm->resolution.x = CELL_SIZE * gm->map->lenght;
		gm->c_size.x = CELL_SIZE;
	}
	if (gm->resolution.y > sizey)
	{
		gm->resolution.y = sizey - (sizey % gm->map->height);
		gm->c_size.y = (int)(sizey / gm->map->height);
	}
	else
	{
		gm->resolution.y = CELL_SIZE * gm->map->height;
		gm->c_size.y = CELL_SIZE;
	}
	return ;
}

int	checkresutils(t_game *gm)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	mlx_get_screen_size(gm->mlx, &sizex, &sizey);
	rescheck(gm, sizex, sizey);
	return (1);
}

t_img	init_xpm(t_game *gm, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(gm->mlx, path,
			&(img.size.y), &(img.size.x));
	img.mimg.data = (int *)mlx_get_data_addr(img.img,
			&img.mimg.bpp, &img.mimg.size_l, &img.mimg.endian);
	return (img);
}

t_mlx_img	create_image(t_game *gm, int lenght, int height)
{
	t_mlx_img	img;

	if (lenght <= 0)
		lenght = 1;
	if (height <= 0)
		height = 1;
	img.img_ptr = mlx_new_image(gm->mlx,
			lenght, height);
	img.data = (int *)mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.size_l, &img.endian);
	img.height = height;
	img.width = lenght;
	return (img);
}

int	get_col_i(t_game *gm, t_vector2 pos)
{
	t_coll	col;
	int		x;

	x = -1;
	while (++x < gm->map->col_amount)
	{
		col = gm->colls[x];
		if (pos.x == col.pos.x && pos.y == col.pos.y)
			return (x);
	}
	return (-1);
}
