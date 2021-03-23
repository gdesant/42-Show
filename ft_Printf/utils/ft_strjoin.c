/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (!(tab = (char *)malloc(sizeof(char) * \
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i] != 0)
		{
			tab[i] = s1[i];
			i++;
		}
		while (s2[j] != 0)
		{
			tab[i + j] = s2[j];
			j++;
		}
		tab[i + j] = '\0';
		return (tab);
	}
	return (NULL);
}
