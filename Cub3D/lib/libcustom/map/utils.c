/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int		ft_strlen_nspace(char *line)
{
	int i;
	int t;

	t = 0;
	i = 0;
	while (line[i++])
		if (line[i] != ' ' || line[i] != '	')
			t++;
	return (t);
}

int		ft_ccmp(char temp, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (temp == src[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_stock_size(char **stock)
{
	int i;

	i = 0;
	while (stock[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst[i]);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				src;

	src = 0;
	i = 0;
	while (i < n)
	{
		src = src + (s1[i] - s2[i]);
		if (s1[i] != s2[i])
			return (src);
		i++;
	}
	return (src);
}
