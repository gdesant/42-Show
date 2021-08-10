/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_imgs(t_game *gm)
{
	int	i;

	i = -1;
	mlx_destroy_image(gm->mlx, gm->tex.free.img);
	mlx_destroy_image(gm->mlx, gm->tex.wall.img);
	mlx_destroy_image(gm->mlx, gm->tex.pl_u.img);
	mlx_destroy_image(gm->mlx, gm->tex.pl_d.img);
	mlx_destroy_image(gm->mlx, gm->tex.pl_l.img);
	mlx_destroy_image(gm->mlx, gm->tex.pl_r.img);
	mlx_destroy_image(gm->mlx, gm->tex.exit_cl.img);
	mlx_destroy_image(gm->mlx, gm->tex.exit_op.img);
	mlx_destroy_image(gm->mlx, gm->grid.img_ptr);
	while (++i < gm->tex.coll.count)
		mlx_destroy_image(gm->mlx, gm->tex.coll.imgs[i].img);
	free(gm->tex.coll.imgs);
	return ;
}

int	clean_exit(t_game *gm)
{
	int	score;
	int	win;

	score = gm->pl.mov_amount;
	win = FALSE;
	if (gm->pl.coll_picked == gm->pl.coll_amount
		&& gm->pl.pos.x == gm->map->exit_pos.x
		&& gm->pl.pos.y == gm->map->exit_pos.y)
		win = TRUE;
	free(gm->colls);
	free_map(gm->map);
	free(gm->map);
	free_imgs(gm);
	mlx_destroy_window(gm->mlx, gm->window);
	free(gm->mlx);
	free(gm);
	debug_win(win, score);
	exit(0);
}

int	launch_sl(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->isInit)
		init_so_long(game);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_loop_hook(game->mlx, keys_handler, game);
	mlx_hook(game->window, 2, 1, on_pressed_event, game);
	mlx_hook(game->window, 3, 2, on_released_event, game);
	mlx_hook(game->window, ClientMessage,
		StructureNotifyMask, &clean_exit, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*gm;
	int		err;

	gm = NULL;
	err = 0;
	if (!maincheckerror(argc, argv, &fd))
		return (0);
	gm = malloc(sizeof(t_game));
	gm->window = NULL;
	gm->isInit = 0;
	err = map_init(gm, argv[1]);
	if (err > 0)
	{
		printf("Extinction du jeu ...\n");
		free(gm);
		exit(-1);
	}
	printf("Lancement du jeu ...\n\n");
	return (launch_sl(gm));
}
