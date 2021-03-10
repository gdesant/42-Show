/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	headerf_bmp(int fs, int fd)
{
	int		i;
	char	tmp[14];

	i = 0;
	while (i < 14)
		tmp[i++] = 0;
	tmp[0] = (unsigned char)('B');
	tmp[1] = (unsigned char)('M');
	tmp[2] = (unsigned char)(fs);
	tmp[3] = (unsigned char)(fs >> 8);
	tmp[4] = (unsigned char)(fs >> 16);
	tmp[5] = (unsigned char)(fs >> 24);
	tmp[10] = (unsigned char)(54);
	write(fd, tmp, 14);
	return ;
}

void	headeri_bmp(t_game *gm, int fd)
{
	int		i;
	char	tmp[40];

	i = 0;
	while (i < 40)
		tmp[i++] = 0;
	tmp[0] = (unsigned char)(40);
	tmp[4] = (unsigned char)(gm->mf->resolution.x);
	tmp[5] = (unsigned char)(gm->mf->resolution.x >> 8);
	tmp[6] = (unsigned char)(gm->mf->resolution.x >> 16);
	tmp[7] = (unsigned char)(gm->mf->resolution.x >> 24);
	tmp[8] = (unsigned char)(gm->mf->resolution.y);
	tmp[9] = (unsigned char)(gm->mf->resolution.y >> 8);
	tmp[10] = (unsigned char)(gm->mf->resolution.y >> 16);
	tmp[11] = (unsigned char)(gm->mf->resolution.y >> 24);
	tmp[12] = (unsigned char)(1);
	tmp[14] = (unsigned char)(32);
	write(fd, tmp, 40);
	return ;
}

void	header_bmp(t_game *gm, int fd)
{
	int		i;
	int		j;
	char	tmp[4];

	i = gm->mf->resolution.x * (gm->mf->resolution.y - 1);
	j = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < gm->mf->resolution.x)
		{
			tmp[0] = (unsigned char)(gm->screen.data[i] % 256);
			tmp[1] = (unsigned char)(gm->screen.data[i] / 256 % 256);
			tmp[2] = (unsigned char)(gm->screen.data[i] / 256 / 256 % 256);
			tmp[3] = (unsigned char)(0);
			write(fd, tmp, 4);
			i++;
			j++;
		}
		i -= 2 * gm->mf->resolution.x;
	}
	return ;
}

void	save_bmp(t_game *gm)
{
	int	fs;
	int	fd;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	gm->mlx = mlx_init();
	init_pl(gm);
	fs = (gm->mf->resolution.x * gm->mf->resolution.y) + 14 + 40;
	headerf_bmp(fs, fd);
	headeri_bmp(gm, fd);
	if (raycast(gm))
	{
		draw_walls(gm);
		print_sprites(gm);
	}
	header_bmp(gm, fd);
	return ;
}
