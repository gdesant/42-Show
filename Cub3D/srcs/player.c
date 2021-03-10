/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	turn_player(t_game *gm, int dir)
{
	double	dist;

	gm->pl.rotx = gm->pl.rotx * cos(dir * TN) - gm->pl.roty * sin(dir * TN);
	gm->pl.roty = gm->pl.roty * cos(dir * TN) + gm->pl.rotx * sin(dir * TN);
	dist = hypot(gm->pl.rotx, gm->pl.roty);
	gm->pl.rotx /= dist;
	gm->pl.roty /= dist;
}

void	move_front(t_game *gm, int dir)
{
	gm->pl.x += dir * (gm->pl.rotx * SPEED / 101);
	if (gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] == '1')
		gm->pl.x -= dir * (gm->pl.rotx * SPEED / 101);
	gm->pl.y += dir * (gm->pl.roty * SPEED / 101);
	if (gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] == '1')
		gm->pl.y -= dir * (gm->pl.roty * SPEED / 101);
	if (gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] == '2')
	{
		gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] = '0';
		gm->spritelen--;
		gm->pl.icount++;
	}
}

void	move_side(t_game *gm, int dir)
{
	gm->pl.x -= dir * (gm->pl.roty * SPEED / 101);
	if (gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] == '1')
		gm->pl.x += dir * (gm->pl.roty * SPEED / 101);
	gm->pl.y += dir * (gm->pl.rotx * SPEED / 101);
	if (gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] == '1')
		gm->pl.y -= dir * (gm->pl.rotx * SPEED / 101);
	if (gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] == '2')
	{
		gm->mf->map.maparray[(int)floor(gm->pl.y)][(int)floor(gm->pl.x)] = '0';
		gm->spritelen--;
		gm->pl.icount++;
	}
}
