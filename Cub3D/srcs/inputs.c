/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		keys_handler(t_game *gm)
{
	if (gm->pl.icount == gm->ispritelen)
		return (0);
	if (gm->inputs.z)
		move_front(gm, 1);
	if (gm->inputs.s)
		move_front(gm, -1);
	if (gm->inputs.q)
		move_side(gm, -1);
	if (gm->inputs.d)
		move_side(gm, 1);
	if (gm->inputs.a)
		turn_player(gm, -1);
	if (gm->inputs.e)
		turn_player(gm, 1);
	return (0);
}

void	set_key(t_game *gm, int key, int state)
{
	if (key == KEY_ESC)
		gm->inputs.esc = state;
	else if (key == KEY_Z)
		gm->inputs.z = state;
	else if (key == KEY_S)
		gm->inputs.s = state;
	else if (key == KEY_Q)
		gm->inputs.q = state;
	else if (key == KEY_D)
		gm->inputs.d = state;
	else if (key == KEY_A)
		gm->inputs.a = state;
	else if (key == KEY_E)
		gm->inputs.e = state;
	else if (key == KEY_R)
		gm->inputs.r = state;
}

int		on_pressed_event(int key, t_game *gm)
{
	set_key(gm, key, 1);
	return (1);
}

int		on_released_event(int key, t_game *gm)
{
	set_key(gm, key, 0);
	return (1);
}
