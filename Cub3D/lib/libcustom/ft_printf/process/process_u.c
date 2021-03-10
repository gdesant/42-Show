/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		get_size_longi(long int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = 4294967296 + n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_longi_toa(long int n)
{
	char	*str;
	int		i;
	int		len;

	len = get_size_longi(n);
	if (!(str = malloc((len + 1) * sizeof(*str))))
		return (NULL);
	i = len - 1;
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

void	get_u(t_data *t)
{
	unsigned int	nbr;
	char			*nbr_str;

	t->flag.minus == 1 ? t->flag.zero = 0 : 0;
	nbr = (unsigned int)va_arg(t->valist, unsigned int);
	if (nbr || nbr == 0)
	{
		nbr_str = ft_longi_toa(nbr);
		t->bf = ft_strdup(nbr_str);
		if (t->bf)
			print_nbr(t);
	}
}
