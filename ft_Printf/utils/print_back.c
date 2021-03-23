/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_back.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_back(const char *fmt, t_data *t)
{
	int c;

	c = t->i;
	while (fmt[t->i] != '%')
		t->i--;
	while (t->i <= c)
		t->nb_print += write(t->fd, fmt + (t->i)++, 1);
}