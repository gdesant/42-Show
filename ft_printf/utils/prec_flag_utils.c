/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_flag_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_prec(const char *fmt, t_data *t)
{
	if (t->flag.prec >= 0)
	{
		t->i++;
		return ;
	}
	else if (fmt[t->i] == '.' && fmt[t->i + 1] == '*')
	{
		t->flag.prec = va_arg(t->valist, int);
		t->i += 2;
	}
	else if (fmt[t->i] == '.' && ft_isdigit(fmt[t->i + 1]))
	{
		t->i++;
		t->flag.prec = ft_atoi(fmt + t->i);
		while (ft_isdigit(fmt[t->i]))
			t->i++;
	}
	else
		t->flag.prec = 0;
}

void	init_flag(t_data *t)
{
	t->flag.minus = 0;
	t->flag.zero = 0;
	t->flag.width = 0;
	t->flag.prec = -1;
	t->flag.neg = 0;
}
