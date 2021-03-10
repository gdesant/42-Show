/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	print_rest_0_or_space(t_data *t)
{
	int len;
	int	space;

	if (t->flag.neg == 1)
		len = (int)ft_strlen(t->bf) + 1;
	else
		len = (int)ft_strlen(t->bf);
	space = t->flag.width - ((t->flag.prec > (int)ft_strlen(t->bf) ?\
				t->flag.prec : 0) + len);
	while (space > 0)
	{
		if (t->flag.zero == 1)
			t->nb_print += write(t->fd, "0", 1);
		else
			t->nb_print += write(t->fd, " ", 1);
		space--;
	}
}

void	print_neg_sign(t_data *t)
{
	if (t->flag.neg == 1)
		t->nb_print += write(t->fd, "-", 1);
}

void	check_sign_nbr(t_data *t)
{
	char *tmp;

	if (t->bf[0] == '-')
	{
		tmp = ft_strdup(t->bf + 1);
		free(t->bf);
		t->bf = tmp;
		t->flag.neg = 1;
	}
}

void	print_nbr(t_data *t)
{
	get_prec(t);
	if (t->flag.minus == 1)
	{
		print_neg_sign(t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
		print_rest_0_or_space(t);
	}
	else if (t->flag.zero == 1)
	{
		print_neg_sign(t);
		print_rest_0_or_space(t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	else
	{
		print_rest_0_or_space(t);
		print_neg_sign(t);
		t->nb_print += write(t->fd, t->bf, ft_strlen(t->bf));
	}
	t->i++;
	free(t->bf);
	t->bf = NULL;
}

void	get_int(t_data *t)
{
	int		nbr;
	char	*nbr_str;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	nbr = (int)va_arg(t->valist, int);
	if (nbr || nbr == 0)
	{
		nbr_str = ft_itoa(nbr);
		t->bf = ft_strdup(nbr_str);
		free(nbr_str);
		if (t->bf)
			print_nbr(t);
	}
}
