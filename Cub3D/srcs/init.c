/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_sprites(t_game *gm)
{
	int x;
	int y;
	int count;

	count = 0;
	x = 0;
	y = 0;
	gm->sprites = malloc(sizeof(t_sprite) * gm->spritelen);
	while (y < gm->mf->map.height)
	{
		while (x < ft_strlen(gm->mf->map.maparray[y]))
		{
			if (gm->mf->map.maparray[y][x] == '2')
			{
				gm->sprites[count].pos.x = x + 0.5;
				gm->sprites[count].pos.y = y + 0.5;
				count++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	init_tex2(t_game *gm)
{
	int height;
	int lenght;

	gm->mf->tex.sprite.img = mlx_xpm_file_to_image(gm->mlx,
		gm->mf->tex.sprite.path, &height, &lenght);
	gm->mf->tex.sprite.mimg.data = (int*)mlx_get_data_addr(
		gm->mf->tex.sprite.img, &gm->mf->tex.sprite.mimg.bpp,
		&gm->mf->tex.sprite.mimg.size_l, &gm->mf->tex.sprite.mimg.endian);
	gm->endtex.img_ptr = mlx_xpm_file_to_image(gm->mlx, "./textures/end.xpm",
		&height, &lenght);
	gm->endtex.data = (int*)mlx_get_data_addr(gm->endtex.img_ptr,
		&gm->endtex.bpp, &gm->endtex.size_l, &gm->endtex.endian);
	init_sprites(gm);
	init_end(gm);
}

void	init_tex(t_game *gm)
{
	int height;
	int lenght;

	gm->mf->tex.no.img = mlx_xpm_file_to_image(gm->mlx, gm->mf->tex.no.path,
		&height, &lenght);
	gm->mf->tex.no.mimg.data = (int*)mlx_get_data_addr(gm->mf->tex.no.img,
		&gm->mf->tex.no.mimg.bpp, &gm->mf->tex.no.mimg.size_l,
		&gm->mf->tex.no.mimg.endian);
	gm->mf->tex.so.img = mlx_xpm_file_to_image(gm->mlx, gm->mf->tex.so.path,
		&height, &lenght);
	gm->mf->tex.so.mimg.data = (int*)mlx_get_data_addr(gm->mf->tex.so.img,
		&gm->mf->tex.so.mimg.bpp, &gm->mf->tex.so.mimg.size_l,
		&gm->mf->tex.so.mimg.endian);
	gm->mf->tex.ea.img = mlx_xpm_file_to_image(gm->mlx, gm->mf->tex.ea.path,
		&height, &lenght);
	gm->mf->tex.ea.mimg.data = (int*)mlx_get_data_addr(gm->mf->tex.ea.img,
		&gm->mf->tex.ea.mimg.bpp, &gm->mf->tex.ea.mimg.size_l,
		&gm->mf->tex.ea.mimg.endian);
	gm->mf->tex.we.img = mlx_xpm_file_to_image(gm->mlx, gm->mf->tex.we.path,
		&height, &lenght);
	gm->mf->tex.we.mimg.data = (int*)mlx_get_data_addr(gm->mf->tex.we.img,
		&gm->mf->tex.we.mimg.bpp, &gm->mf->tex.we.mimg.size_l,
		&gm->mf->tex.we.mimg.endian);
	init_tex2(gm);
}

void	init_key(t_inputmanager *in)
{
	in->z = 0;
	in->s = 0;
	in->q = 0;
	in->d = 0;
	in->a = 0;
	in->e = 0;
	in->esc = 0;
	in->r = 0;
	return ;
}

int		init_pl(t_game *gm)
{
	gm->pl = gm->mf->pl;
	gm->pl.icount = 0;
	gm->pl.x += 0.5;
	gm->pl.y += 0.5;
	gm->pl.ang = fixang(init_ang(gm));
	gm->pl.rotx = cos(gm->pl.ang * (M_PI / 180.0));
	gm->pl.roty = -sin(gm->pl.ang * (M_PI / 180.0));
	gm->spritelen = count_case(gm, '2');
	if (gm->spritelen < 1)
		gm->spritelen = 1;
	gm->ispritelen = gm->spritelen;
	init_rays(gm);
	init_key(&gm->inputs);
	gm->screen.img_ptr = mlx_new_image(gm->mlx,
	gm->mf->resolution.x, gm->mf->resolution.y);
	gm->screen.data = (int *)mlx_get_data_addr(gm->screen.img_ptr,
		&gm->screen.bpp, &gm->screen.size_l, &gm->screen.endian);
	gm->endimg.img_ptr = mlx_new_image(gm->mlx, gm->mf->resolution.x,
		gm->mf->resolution.y);
	gm->endimg.data = (int *)mlx_get_data_addr(gm->endimg.img_ptr,
		&gm->endimg.bpp, &gm->endimg.size_l, &gm->endimg.endian);
	gm->screen.width = gm->mf->resolution.x;
	gm->screen.height = gm->mf->resolution.y;
	init_tex(gm);
	return (1);
}
