/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_dir(t_vector2 dir)
{
	if (dir.y == 1 && dir.x == 0)
		return (MOVE_DOWN);
	if (dir.y == -1 && dir.x == 0)
		return (MOVE_UP);
	if (dir.x == 1 && dir.y == 0)
		return (MOVE_RIGHT);
	if (dir.x == -1 && dir.y == 0)
		return (MOVE_LEFT);
	return (FALSE);
}

int	move_to_col(t_game *gm, t_vector2 pos)
{
	t_coll	*col;

	if (get_col_i(gm, pos) == -1)
		return (FALSE);
	col = &gm->colls[get_col_i(gm, pos)];
	if (!col->is_pick)
	{
		col->is_pick = TRUE;
		gm->pl.coll_picked++;
		return (TRUE + 1);
	}
	return (TRUE);
}

int	move(t_game *gm, t_vector2 new_pos, int *col)
{
	if (gm->map->maparray[new_pos.y][new_pos.x] == '1')
		return (MOV_ERR_WA);
	if (gm->map->maparray[new_pos.y][new_pos.x] == 'E')
	{
		if (gm->pl.coll_amount != gm->pl.coll_picked)
			return (MOV_ERR_DR);
		else
		{
			gm->pl.pos = new_pos;
			gm->pl.mov_amount++;
			clean_exit(gm);
		}
	}
	if (gm->map->maparray[new_pos.y][new_pos.x] == 'C')
	{
		*col = move_to_col(gm, new_pos);
		if (!*col)
			return (MOV_ERR_WA);
		if (*col == 2)
			*col = TRUE;
		else if (*col == 1)
			*col = FALSE;
	}
	return (TRUE);
}

int	move_to(t_game *gm, t_vector2 direction, int *key_state)
{
	t_vector2	new_pos;
	int			col;

	*key_state = 0;
	new_pos = create_vector2(gm->pl.pos.x + direction.x,
			 gm->pl.pos.y + direction.y);
	col = FALSE;
	if (!is_valid_dir(direction))
		return (debug_mov_error(direction, MOV_ERR_WD));
	if (move(gm, new_pos, &col) <= 0)
		return (debug_mov_error(new_pos, move(gm, new_pos, &col)));
	gm->pl.last_mov = is_valid_dir(direction);
	gm->pl.pos = new_pos;
	gm->pl.mov_amount++;
	if (col)
		printf("%s{x:%d, y:%d}%s%d%s%d\n",
			"- Le joueur c'est déplacer sur la case ", new_pos.x, new_pos.y,
			" et à récuperer un coin, plus que ",
			gm->pl.coll_amount - gm->pl.coll_picked, " ! MovementCount: ",
			gm->pl.mov_amount);
	else
		printf("%s {x:%d, y:%d} ! MovementCount: %d\n",
			"- Le joueur c'est déplacer sur la case",
			new_pos.x, new_pos.y, gm->pl.mov_amount);
	return (FALSE);
}
