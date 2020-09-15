/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (NULL);
	if (*s == '\0' || len < 0)
		return ("");
	if (start > ft_strlen(s))
		return ("");
	if (*s != '\0')
	{
		if (!(dest = malloc(sizeof(*dest) * len + 1)))
			return (NULL);
		i = 0;
		while (s[start] != '\0' && i < len)
		{
			dest[i] = (char)s[start];
			i++;
			start++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return ("");
}
