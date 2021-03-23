/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_data *t)
{
	t->flag.width = va_arg(t->valist, int);
	if (t->flag.width < 0)
	{
		t->flag.width = -(t->flag.width);
		t->flag.minus = 1;
	}
}

void	parse_flag(const char *fmt, t_data *t)
{
	while (ft_strchr("-0*.123456789", fmt[t->i]))
	{
		fmt[t->i] == '-' ? t->flag.minus = 1 : 0;
		fmt[t->i] == '0' ? t->flag.zero = 1 : 0;
		fmt[t->i] == '*' ? parse_width(t) : 0;
		if (fmt[t->i] == '.')
			parse_prec(fmt, t);
		else if (ft_isdigit(fmt[t->i]))
		{
			t->flag.width = ft_atoi(fmt + t->i);
			while (ft_isdigit(fmt[t->i]))
				t->i++;
		}
		else
			t->i++;
	}
}

void	parse_type(const char *fmt, t_data *t)
{
	if (fmt[t->i] == 'c' || fmt[t->i] == 's')
		get_char(fmt[t->i], t);
	else if (fmt[t->i] == 'd' || fmt[t->i] == 'i')
		get_int(t);
	else if (fmt[t->i] == 'x' || fmt[t->i] == 'X')
		get_hex(fmt[t->i], t);
	else if (fmt[t->i] == 'u')
		get_u(t);
	else if (fmt[t->i] == 'p')
		get_p(t);
	else if (fmt[t->i] == '%')
		get_percent(t);
	else if (fmt[t->i] != '\0')
		print_back(fmt, t);
}

void	parse(const char *fmt, t_data *t)
{
	t->i++;
	init_flag(t);
	parse_flag(fmt, t);
	if (t->i > (int)ft_strlen(fmt) - 1)
		return ;
	parse_type(fmt, t);
}

int		ft_printf(const char *fmt, ...)
{
	t_data t;

	ft_bzero(&t, sizeof(t));
	va_start(t.valist, fmt);
	if ((t.fd = 1) && fmt)
	{
		t.len = (int)ft_strlen(fmt);
		while (t.i < t.len)
		{
			if (fmt[t.i] == '%' && t.len == 1)
				break ;
			else if (fmt[t.i] == '%' && fmt[t.i + 1] == '%')
			{
				t.nb_print += write(t.fd, "%", 1);
				t.i += 2;
			}
			else if (fmt[t.i] == '%' && fmt[t.i + 1] != '%')
				parse(fmt, &t);
			else
				t.nb_print += write(t.fd, fmt + (t.i)++, 1);
		}
	}
	va_end(t.valist);
	return (t.nb_print);
}
