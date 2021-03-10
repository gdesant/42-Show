/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		clean_exit(t_game *gm)
{
	mlx_destroy_image(gm->mlx, gm->mf->tex.no.img);
	mlx_destroy_image(gm->mlx, gm->mf->tex.so.img);
	mlx_destroy_image(gm->mlx, gm->mf->tex.ea.img);
	mlx_destroy_image(gm->mlx, gm->mf->tex.we.img);
	mlx_destroy_image(gm->mlx, gm->mf->tex.sprite.img);
	mlx_destroy_image(gm->mlx, gm->screen.img_ptr);
	mlx_destroy_image(gm->mlx, gm->endimg.img_ptr);
	free(gm->ray_array);
	free(gm->sprites);
	free_map(gm->mf);
	if (gm->window != NULL)
		mlx_destroy_window(gm->mlx, gm->window);
	if (gm->mlx != NULL)
		free(gm->mlx);
	free(gm);
	exit(0);
	return (0);
}

int		checkresutils(t_game *gm)
{
	int sizex;
	int sizey;

	sizex = 0;
	sizey = 0;
	mlx_get_screen_size(gm->mlx, &sizex, &sizey);
	if (gm->mf->resolution.x > sizex)
		gm->mf->resolution.x = sizex;
	if (gm->mf->resolution.y > sizey)
		gm->mf->resolution.y = sizey;
	return (1);
}

int		maincheckerror(int argc, char **argv, int *fd)
{
	if (argc < 2)
	{
		ft_printf("Trop peu d'argument :\n./Cub3d [map_path] (--save)\n");
		return (0);
	}
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_printf("Impossible d'ouvrir la map !\n", 2);
		return (0);
	}
	if (argc > 3)
	{
		ft_printf("Trop d'argument :\n./Cub3d [map_path] (--save)\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_game	*gm;

	gm = NULL;
	if (!maincheckerror(argc, argv, &fd))
		return (0);
	gm = malloc(sizeof(t_game));
	gm->window = NULL;
	if (!map_init(gm, argv[1]))
	{
		free(gm);
		exit(-1);
	}
	if (argc == 2)
		game(gm);
	else if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
		save_bmp(gm);
	else
	{
		ft_printf("Erreur argument:\n./Cub3d [map_path] (--save)\n");
		return (0);
	}
	clean_exit(gm);
	return (1);
}
