/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int				get_size_hex(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = 4294967296 + n;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	i++;
	return (i);
}

static char		base_x(int d, char type)
{
	char	c;

	c = '\0';
	if (d < 16 && type == 'x')
		c = d - 10 + 'a';
	else if (d < 16 && type == 'X')
		c = d - 10 + 'A';
	return (c);
}

char			*ft_itox(long int n, char type)
{
	char	*str;
	int		i;
	int		len;
	int		d;

	len = get_size_hex(n);
	if (!(str = malloc((len + 1) * sizeof(*str))))
		return (NULL);
	i = len - 1;
	str[len] = '\0';
	if (n < 0)
		n = 4294967296 + n;
	while (n >= 16)
	{
		d = n % 16;
		str[i] = (d < 10 ? (d + '0') : base_x(d, type));
		n = n / 16;
		i--;
	}
	str[i] = (n < 10 ? (n + '0') : base_x(n, type));
	return (str);
}
