/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

t_vector2	create_vector2(int x, int y)
{
	t_vector2	buff;

	buff.x = x;
	buff.y = y;
	return (buff);
}

int	isnull_vector2(t_vector2 vector)
{
	if (vector.x == -1 && vector.y == -1)
		return (TRUE);
	return (FALSE);
}
