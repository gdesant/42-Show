/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		neg;
}t_flag;

typedef struct s_data
{
	t_flag			flag;
	va_list			valist;
	char			*bf;
	int				i;
	int				fd;
	int				nb_print;
	int				len;
}t_data;

void				ft_bzero(void *str, size_t n);
int					ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, int start, size_t len);
char				*ft_itoa(int n);
int					get_size(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);

#endif
