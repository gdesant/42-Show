/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int	check_color_err(char **stock, t_color *clr)
{
	if (ft_stock_size(stock) != 3 || clr->s == 1)
	{
		if (ft_stock_size(stock) != 3)
			ft_printf("Erreur d'argument couleur !\n");
		else if (clr->s == 1)
			ft_printf("Double entrée pour une couleur !\n");
		else
			return (0);
		return (1);
	}
	return (0);
}

int	check_line_error(char *file, t_mapfile *mp)
{
	if (ft_ccmp(file[0], "RNSWEFC"))
	{
		if (mp->map.c > -1)
		{
			ft_printf("Source line après la map !\n");
			return (0);
		}
		if (!treatsrcline(file, mp))
		{
			ft_printf("Erreur source ! \n--> %s\n", file);
			return (0);
		}
	}
	else if (ismapline(file))
	{
		if (!treatmapline(file, mp) && mp->map.e == 0)
			return (0);
		else if (mp->map.e == 1)
		{
			ft_printf("Multiple map dans map.cub !\n");
			return (0);
		}
	}
	return (1);
}

int	contain_digit(char *src)
{
	int n;

	n = 0;
	while (src[n])
	{
		if (ft_isdigit(src[n]))
			return (1);
		n++;
	}
	return (0);
}
