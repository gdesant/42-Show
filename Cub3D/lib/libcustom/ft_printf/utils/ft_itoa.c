/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int				get_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static size_t	num_len(long int n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		return (1 + num_len(n / 10));
	return (1);
}

static void		set_str(char *str, long int n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (i <= len)
	{
		str[len] = (n % 10) + '0';
		n = (n / 10);
		len--;
	}
}

void			*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (!(tab = malloc(size * count)))
		return (0);
	ft_bzero(tab, count * size);
	return (tab);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len_n;

	len_n = num_len(n);
	if (n < 0)
		len_n++;
	if (!(str = ft_calloc(len_n + 1, sizeof(char))))
		return (0);
	set_str(str, n, len_n - 1);
	return (str);
}
