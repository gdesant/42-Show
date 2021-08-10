/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strendwith(char *line, char *end)
{
	int	i;

	if (ft_strlen(end) > ft_strlen(line))
		return (FALSE);
	i = ft_strlen(line);
	line += i - ft_strlen(end);
	i = -1;
	while (line[++i])
		if (line[i] != end[i])
			return (FALSE);
	return (TRUE);
}

int	maincheckerror(int argc, char **argv, int *fd)
{
	if (argc < 2)
	{
		printf("Trop peu d'argument :\n./so_long [map_path]\n");
		return (0);
	}
	else if (argc > 2)
	{
		printf("Trop d'argument :\n./so_long [map_path]\n");
		return (0);
	}
	else if (ft_strendwith(argv[1], MAP_EXTENSION) == FALSE)
	{
		printf("Format de map inconnu ! \nRequired Format: \".ber\"\n");
		return (0);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		printf("Impossible d'ouvrir la map !\n");
		return (0);
	}
	return (1);
}

void	debug_win(int win, int score)
{
	printf("----------------------------------------------");
	printf("----------------------------------------------\n");
	if (win)
		printf("\t\t\t   Vous avez gagné avec %d movements !\n %s%s", score,
			"\t\t\tEssayez de faire mieux la prochaine fois !\n",
			"\t\t\t    Extinction du jeu ... A bientot !\n");
	else
		printf("\t\t\tVous avez abandonné à %d movements !\n%s", score,
			"\t\t\t Extinction du jeu ... A bientot !\n");
	printf("----------------------------------------------");
	printf("----------------------------------------------\n");
	return ;
}

int	debug_mov_error(t_vector2 new_pos, int err)
{
	if (err == MOV_ERR_WA)
		printf("!!!\t%s {x:%d, y:%d} car c'est un mur\t!!!\n",
			"Vous ne pouvez pas aller sur la case", new_pos.x + 1,
			new_pos.y + 1);
	else if (err == MOV_ERR_DR)
		printf("!!!\tVous ne pouvez pas aller à travers %s\t!!!\n",
			"la porte car vous n'avez récolter toutes les pièces");
	else if (err == MOV_ERR_WD)
		printf("%s {x:%d, y:%d}\t!!!\n",
			"!!!\tVous ne pouvez pas aller dans la direction", new_pos.x,
			new_pos.y);
	return (FALSE);
}
