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

typedef struct		s_flag
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		neg;
}					t_flag;

typedef struct		s_data
{
	t_flag			flag;
	va_list			valist;
	char			*bf;
	int				i;
	int				fd;
	int				nb_print;
	int				len;
}					t_data;

void				fillwidth_char(t_data *t);
void				print_char(t_data *t, unsigned char ch);
void				get_char(char type, t_data *t);
void				fillwidth_str(t_data *t);
void				print_str(t_data *t);
void				get_int(t_data *t);
void				print_nbr(t_data *t);
void				check_sign_nbr(t_data *t);
void				print_neg_sign(t_data *t);
void				print_rest_0_or_space(t_data *t);
void				get_prec(t_data *t);
void				get_hex(char type, t_data *t);
char				*ft_itox(long int n, char type);
int					get_size_hex(long int n);
void				get_u(t_data *t);
char				*ft_longi_toa(long int n);
int					get_size_longi(long int n);
void				print_rest_0_or_space_addr(t_data *t);
void				print_addr(t_data *t);
void				get_p(t_data *t);
void				init_flag(t_data *t);
void				parse_flag(const char *fmt, t_data *t);
void				parse_type(const char *fmt, t_data *t);
void				parse(const char *fmt, t_data *t);
int					ft_printf(const char *fmt, ...);
void				parse_prec(const char *fmt, t_data *t);
void				parse_width(t_data *t);
void				print_back(const char *fmt, t_data *t);
void				ft_bzero(void *str, size_t n);
int					ft_strlen(const char *str);
char				*ft_strchr(const char *s, int c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, int start, size_t len);
char				*ft_itoa(int n);
int					get_size(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
void				init_flag(t_data *t);
void				print_back(const char *fmt, t_data *t);
void				get_prec(t_data *t);
void				get_percent(t_data *t);

#endif
