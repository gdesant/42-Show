/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main_loop(t_game *gm)
{
	keys_handler(gm);
	if (gm->inputs.esc)
		clean_exit(gm);
	else if (gm->pl.icount == gm->ispritelen)
		return (end_game_loop(gm));
	else if (raycast(gm))
	{
		draw_walls(gm);
		print_sprites(gm);
		mlx_put_image_to_window(gm->mlx, gm->window, gm->screen.img_ptr, 0, 0);
	}
	return (1);
}

void	init_end(t_game *gm)
{
	int x;
	int i;
	int y;
	int px;

	px = 0;
	x = 0;
	y = 0;
	while (y < gm->mf->resolution.y)
	{
		while (x < gm->mf->resolution.x)
		{
			i = (int)(floor(((double)y / gm->mf->resolution.y) * 108) * 192);
			i += (int)floor(((double)x / gm->mf->resolution.x) * 192);
			px = gm->endtex.data[i];
			gm->endimg.data[(y * gm->mf->resolution.x) + x] = px;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_destroy_image(gm->mlx, gm->endtex.img_ptr);
}

int		end_game_loop(t_game *gm)
{
	if (gm->inputs.r)
		return (reset_game(gm));
	mlx_put_image_to_window(gm->mlx, gm->window, gm->endimg.img_ptr, 0, 0);
	return (1);
}

int		reset_game(t_game *gm)
{
	int x;
	int t;
	int i;

	x = 0;
	gm->pl = gm->mf->pl;
	gm->pl.icount = 0;
	gm->pl.x += 0.5;
	gm->pl.y += 0.5;
	gm->pl.ang = fixang(init_ang(gm));
	gm->pl.rotx = cos(gm->pl.ang * (M_PI / 180.0));
	gm->pl.roty = -sin(gm->pl.ang * (M_PI / 180.0));
	while (gm->spritelen < gm->ispritelen)
	{
		t = (int)floor(gm->sprites[x].pos.y);
		i = (int)floor(gm->sprites[x].pos.x);
		gm->mf->map.maparray[t][i] = '2';
		x = gm->spritelen++;
	}
	return (1);
}

int		game(t_game *gm)
{
	gm->mlx = mlx_init();
	checkresutils(gm);
	gm->window = mlx_new_window(gm->mlx, gm->mf->resolution.x,
		gm->mf->resolution.y, "Cub3D");
	if (gm->window == NULL)
		return (0);
	init_pl(gm);
	mlx_loop_hook(gm->mlx, &main_loop, gm);
	mlx_hook(gm->window, 2, 1, on_pressed_event, gm);
	mlx_hook(gm->window, 3, 2, on_released_event, gm);
	mlx_hook(gm->window, ClientMessage,
		StructureNotifyMask, &clean_exit, gm);
	mlx_loop(gm->mlx);
	return (1);
}
