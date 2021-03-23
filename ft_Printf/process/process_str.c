/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fillwidth_str(t_data *t)
{
	int	i;

	i = t->flag.width - ft_strlen(t->bf);
	while (i > 0)
	{
		t->nb_print += ((t->flag.zero) == 1 ?
			write(t->fd, "0", 1) : write(t->fd, " ", 1));
		i--;
	}
}

void	print_str(t_data *t)
{
	char	*tmp;

	if (t->flag.prec >= 0 && t->flag.prec <= (int)ft_strlen(t->bf))
	{
		tmp = ft_substr(t->bf, 0, t->flag.prec);
		free(t->bf);
		t->bf = tmp;
	}
	if (!(t->bf))
		return ;
	if (t->flag.minus == 1)
	{
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
		fillwidth_str(t);
	}
	else
	{
		fillwidth_str(t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	t->i++;
}
