/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int	free_map(t_mapfile *mf)
{
	free_map_tex(mf);
	free_map_array(mf);
	free(mf);
	return (1);
}

int	free_map_tex(t_mapfile *mf)
{
	if (mf->tex.no.path != NULL)
		free(mf->tex.no.path);
	if (mf->tex.so.path != NULL)
		free(mf->tex.so.path);
	if (mf->tex.we.path != NULL)
		free(mf->tex.we.path);
	if (mf->tex.ea.path != NULL)
		free(mf->tex.ea.path);
	if (mf->tex.sprite.path != NULL)
		free(mf->tex.sprite.path);
	return (1);
}

int	free_map_array(t_mapfile *mf)
{
	int i;

	i = 0;
	while (i <= mf->map.c)
		free(mf->map.maparray[i++]);
	free(mf->map.maparray);
	return (1);
}

int	clean_exit_map(t_mapfile *mf)
{
	free_map(mf);
	ft_printf("Extinction du programme ...\n");
	exit(-1);
}
