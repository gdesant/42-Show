/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_door_state(t_game *gm)
{
	if (gm->pl.coll_picked < gm->pl.coll_amount)
		mlx_string_put(gm->mlx, gm->window, 40, 20, 0XFFFFFF,
			"Door is now open, go through to end the game !");
	else
		mlx_string_put(gm->mlx, gm->window, 40, 20, 0XFFFFFF,
			"Collect all the coins to pay the path to open the door !");
}

int	print_movement(t_game *gm)
{
	char	*buff1;
	char	*buff2;
	char	*buff3;

	buff1 = ft_itoa(gm->pl.mov_amount);
	buff2 = ft_strjoin("Actual Movements: ", buff1);
	mlx_string_put(gm->mlx, gm->window, 40, 40, 0XFFFFFF, buff2);
	free(buff1);
	free(buff2);
	buff1 = ft_itoa(gm->pl.coll_picked);
	buff2 = ft_itoa(gm->pl.coll_amount);
	buff3 = ft_strjoin(buff1, " / ");
	free(buff1);
	buff1 = ft_strjoin(buff3, buff2);
	free(buff2);
	free(buff3);
	buff3 = ft_strjoin("Actual coins: ", buff1);
	mlx_string_put(gm->mlx, gm->window, 40, 60, 0XFFFFFF, buff3);
	free(buff3);
	free(buff1);
	print_door_state(gm);
	return (FALSE);
}

int	printer_grid(t_game *gm)
{
	t_vector2	place;

	place = create_vector2(-1, -1);
	while (++place.y < gm->map->height)
	{
		while (++place.x < gm->map->lenght)
		{
			if (gm->map->maparray[place.y][place.x] == '1')
				print_case_pixel(gm, place, &gm->grid, gm->tex.wall);
			else
				print_case_pixel(gm, place, &gm->grid, gm->tex.free);
		}
		place.x = -1;
	}
	return (FALSE);
}

int	print_entities(t_game *gm)
{
	if (gm->pl.last_mov == MOVE_UP)
		print_case_pixel(gm, gm->pl.pos, &gm->grid, gm->tex.pl_u);
	else if (gm->pl.last_mov == MOVE_DOWN)
		print_case_pixel(gm, gm->pl.pos, &gm->grid, gm->tex.pl_d);
	else if (gm->pl.last_mov == MOVE_LEFT)
		print_case_pixel(gm, gm->pl.pos, &gm->grid, gm->tex.pl_l);
	else if (gm->pl.last_mov == MOVE_RIGHT)
		print_case_pixel(gm, gm->pl.pos, &gm->grid, gm->tex.pl_r);
	if (gm->pl.coll_picked == gm->pl.coll_amount)
		print_case_pixel(gm, gm->map->exit_pos, &gm->grid, gm->tex.exit_op);
	else
		print_case_pixel(gm, gm->map->exit_pos, &gm->grid, gm->tex.exit_cl);
	print_coll(gm);
	return (FALSE);
}

int	printer(t_game *gm)
{
	printer_grid(gm);
	print_entities(gm);
	mlx_put_image_to_window(gm->mlx, gm->window, gm->grid.img_ptr, 0, 0);
	print_movement(gm);
	return (FALSE);
}
