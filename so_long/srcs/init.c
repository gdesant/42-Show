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

#include "../include/so_long.h"

int	init_coll(t_game *gm)
{
	int	x;

	x = -1;
	gm->pl.pos = gm->map->player_pos;
	gm->pl.coll_amount = gm->map->col_amount;
	gm->pl.coll_picked = 0;
	gm->pl.mov_amount = 0;
	gm->pl.last_mov = MOVE_DOWN;
	gm->colls = (t_coll *)malloc(sizeof(t_coll) * gm->map->col_amount);
	while (++x < gm->pl.coll_amount)
		gm->colls[x] = create_coll(gm->map->col_pos[x]);
	return (FALSE);
}

int	init_tex(t_game *gm)
{
	gm->tex.wall = init_xpm(gm, PATH_TEX_OCC);
	gm->tex.free = init_xpm(gm, PATH_TEX_FREE);
	gm->tex.pl_u = init_xpm(gm, PATH_TEX_PL_U);
	gm->tex.pl_d = init_xpm(gm, PATH_TEX_PL_D);
	gm->tex.pl_r = init_xpm(gm, PATH_TEX_PL_R);
	gm->tex.pl_l = init_xpm(gm, PATH_TEX_PL_L);
	gm->tex.exit_op = init_xpm(gm, PATH_TEX_EX_OP);
	gm->tex.exit_cl = init_xpm(gm, PATH_TEX_EX_CL);
	gm->tex.coll.actual_frame = 0;
	gm->tex.coll.count = 6;
	gm->tex.coll.imgs = (t_img *)malloc(sizeof(t_img) * 6);
	gm->tex.coll.imgs[0] = init_xpm(gm, PATH_TEX_COLL_0);
	gm->tex.coll.imgs[1] = init_xpm(gm, PATH_TEX_COLL_1);
	gm->tex.coll.imgs[2] = init_xpm(gm, PATH_TEX_COLL_2);
	gm->tex.coll.imgs[3] = init_xpm(gm, PATH_TEX_COLL_3);
	gm->tex.coll.imgs[4] = init_xpm(gm, PATH_TEX_COLL_4);
	gm->tex.coll.imgs[5] = init_xpm(gm, PATH_TEX_COLL_5);
	return (FALSE);
}

int	init_screen(t_game *gm)
{
	gm->resolution.x = gm->map->lenght * CELL_SIZE;
	gm->resolution.y = gm->map->height * CELL_SIZE;
	checkresutils(gm);
	gm->window = mlx_new_window(gm->mlx, gm->resolution.x, gm->resolution.y,
			"so_long");
	gm->grid = create_image(gm, gm->resolution.x, gm->resolution.y);
	return (FALSE);
}

void	init_key(t_game *gm)
{
	gm->inputs.w = 0;
	gm->inputs.a = 0;
	gm->inputs.s = 0;
	gm->inputs.d = 0;
	gm->inputs.esc = 0;
	return ;
}

void	init_so_long(t_game *gm)
{
	if (!gm->isInit)
	{
		init_screen(gm);
		init_key(gm);
		init_tex(gm);
		init_coll(gm);
		printer(gm);
		mlx_put_image_to_window(gm->mlx, gm->window, gm->grid.img_ptr, 0, 0);
		gm->isInit = TRUE;
	}
	return ;
}
