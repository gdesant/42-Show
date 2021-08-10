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

#include "../include/so_long.h"

int	keys_handler(t_game *gm)
{
	if (gm->isInit == FALSE)
		return (0);
	if (gm->inputs.esc)
		return (clean_exit(gm));
	if (gm->inputs.w)
		move_to(gm, create_vector2(0, -1), &gm->inputs.w);
	else if (gm->inputs.s)
		move_to(gm, create_vector2(0, 1), &gm->inputs.s);
	else if (gm->inputs.a)
		move_to(gm, create_vector2(-1, 0), &gm->inputs.a);
	else if (gm->inputs.d)
		move_to(gm, create_vector2(1, 0), &gm->inputs.d);
	printer(gm);
	return (0);
}

void	set_key(t_game *gm, int key, int state)
{
	if (key == KEY_ESC)
		gm->inputs.esc = state;
	else if (key == KEY_W)
		gm->inputs.w = state;
	else if (key == KEY_S)
		gm->inputs.s = state;
	else if (key == KEY_A)
		gm->inputs.a = state;
	else if (key == KEY_D)
		gm->inputs.d = state;
}

int	on_pressed_event(int key, t_game *gm)
{
	set_key(gm, key, 1);
	return (1);
}

int	on_released_event(int key, t_game *gm)
{
	set_key(gm, key, 0);
	return (1);
}
