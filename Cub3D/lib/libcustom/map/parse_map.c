/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse_map.h"

int		parse_map(int fd, t_game *gm, int mapsize)
{
	int			res;
	char		*file;
	int			err;

	res = 1;
	err = 1;
	gm->mf = malloc(sizeof(t_mapfile));
	initmp(gm->mf);
	gm->mf->map.maparray = (char **)malloc(sizeof(char *) * mapsize + 1);
	gm->mf->map.height = mapsize;
	gm->mf->map.lenght = 0;
	file = NULL;
	while (res > 0)
	{
		res = get_next_line(fd, &file);
		if (gm->mf->map.c > -1 && (file == NULL || file[0] == 0))
			gm->mf->map.e = 1;
		else if (file != NULL && file[0] != 0 && res > -1)
			if (!check_line_error(file, gm->mf))
				err = 0;
		free(file);
	}
	return (err);
}

int		getsrcfile(char *line, t_img *img)
{
	int		i;
	int		x;
	char	*src;
	int		srcsize;

	i = 0;
	x = 0;
	if (img->path != NULL)
	{
		ft_printf("Double entrée pour pour l'une des sources !\n");
		return (0);
	}
	srcsize = ft_strlen_nspace(line);
	src = (char *)malloc(sizeof(char *) * srcsize + 1);
	src[srcsize + 1] = 0;
	while (line[x])
	{
		if (line[x] != ' ')
			src[i++] = line[x];
		x++;
	}
	img->path = src;
	return (1);
}

int		getcolorfile(char *line, t_color *clr)
{
	int		i;
	char	**stock;

	i = 0;
	stock = ft_split(line, ",");
	if (check_color_err(stock, clr) || !contain_digit(stock[0])
		|| !contain_digit(stock[1]) || !contain_digit(stock[2]))
	{
		while (stock[i])
			free(stock[i++]);
		free(stock);
		return (0);
	}
	clr->s = 1;
	clr->r = ft_atoi(stock[0]);
	clr->g = ft_atoi(stock[1]);
	clr->b = ft_atoi(stock[2]);
	while (stock[i])
		free(stock[i++]);
	free(stock);
	if (clr->r > 255 || clr->g > 255 || clr->b > 255)
		return (0);
	return (1);
}

int		getresfile(char *line, t_reso *res)
{
	int		i;
	char	**stock;

	i = 0;
	stock = ft_split(line, " ");
	if (ft_stock_size(stock) != 2 || res->x != -1)
	{
		while (stock[i])
		{
			free(stock[i]);
			i++;
		}
		free(stock);
		ft_printf("Erreur d'argument résolution !\n");
		return (0);
	}
	res->x = ft_atoi(stock[0]);
	res->y = ft_atoi(stock[1]);
	while (stock[i])
	{
		free(stock[i]);
		i++;
	}
	free(stock);
	return (1);
}
