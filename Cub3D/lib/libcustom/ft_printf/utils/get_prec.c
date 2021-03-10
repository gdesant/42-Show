/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	get_prec(t_data *t)
{
	char	*zeros;
	char	*tmp;
	int		i;
	int		len;

	check_sign_nbr(t);
	if (!(t->bf))
		return ;
	len = (int)ft_strlen(t->bf);
	if (t->flag.prec == 0 && t->bf[0] == '0')
		t->bf[0] = '\0';
	else if (t->flag.prec > len)
	{
		i = t->flag.prec - len;
		if (!(zeros = ft_strnew(i)))
			return ;
		while (i > 0)
			zeros[--i] = '0';
		tmp = ft_strjoin(zeros, t->bf);
		free(zeros);
		zeros = NULL;
		free(t->bf);
		t->bf = tmp;
	}
	t->flag.prec >= 0 ? t->flag.zero = 0 : 0;
}
