/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_rest_0_or_space_addr(t_data *t)
{
	int		len;
	int		space;

	if (t->flag.neg == 1)
		len = (int)ft_strlen(t->bf) + 1;
	else
		len = (int)ft_strlen(t->bf);
	space = t->flag.width - ((t->flag.prec > (int)ft_strlen(t->bf) ?\
				t->flag.prec : 0) + len + 2);
	while (space > 0)
	{
		if (t->flag.zero == 1)
			t->nb_print += write(t->fd, "0", 1);
		else
			t->nb_print += write(t->fd, " ", 1);
		space--;
	}
}

void	print_addr(t_data *t)
{
	if (t->flag.minus == 1)
	{
		t->nb_print += write(t->fd, "0x", 2);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
		print_rest_0_or_space_addr(t);
	}
	else if (t->flag.zero == 1)
	{
		t->nb_print += write(t->fd, "0x", 2);
		print_rest_0_or_space_addr(t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	else
	{
		print_rest_0_or_space_addr(t);
		t->nb_print += write(t->fd, "0x", 2);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	t->i++;
	free(t->bf);
	t->bf = NULL;
}

void	get_p(t_data *t)
{
	unsigned long int val;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	if ((val = va_arg(t->valist, unsigned long int)))
	{
		t->bf = ft_itox(val, 'x');
		if (!t->bf)
			return ;
		print_addr(t);
	}
	else if (!val && t->flag.prec != 0)
	{
		t->bf = ft_strdup("0");
		print_addr(t);
	}
	else if (!val && t->flag.prec == 0)
	{
		t->bf = ft_strdup("");
		print_addr(t);
	}
}
