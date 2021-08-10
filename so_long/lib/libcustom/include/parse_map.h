/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H
# include <math.h>
# include "get_next_line.h"

# define MAP_FR '0'
# define MAP_WL '1'
# define MAP_PL 'P'
# define MAP_CL 'C'
# define MAP_EX 'E'
# define MIN_MAP_LEN 3
# define MIN_MAP_HEI 3
# define TRUE 1
# define FALSE 0
# define MAP_ERR_INVALID 1
# define MAP_ERR_OPEN 2
# define MAP_ERR_NOTSQUARE 3
# define MAP_TOO_SMALL 4
# define MAP_ERR_INVALIDCHAR 5
# define MAP_ERR_MISSING_E 6
# define MAP_ERR_MISSING_P 7
# define MAP_ERR_MISSING_C 8
# define MAP_ERR_TOO_E 9
# define MAP_ERR_TOO_P 10
# define MAP_ERR_FRLINE 15

typedef struct s_inputmanager{
	int				w;
	int				a;
	int				s;
	int				d;
	int				esc;
}					t_inputmanager;

typedef struct s_vector2{
	int				x;
	int				y;
}					t_vector2;

typedef struct s_player{
	t_vector2		pos;
	int				coll_amount;
	int				coll_picked;
	int				mov_amount;
	int				last_mov;
}					t_player;

typedef struct s_mlx_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_mlx_img;

typedef struct s_img
{
	void			*img;
	t_vector2		size;
	t_mlx_img		mimg;
}					t_img;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				s;
}					t_color;

typedef struct s_mapdata
{
	int				height;
	int				lenght;
	char			**maparray;
	t_vector2		player_pos;
	t_vector2		exit_pos;
	t_vector2		*col_pos;
	int				col_amount;
	int				err;
	t_vector2		err_pos;
	int				init;
}					t_mapdata;

typedef struct s_coll
{
	int				is_pick;
	t_vector2		pos;
}					t_coll;

typedef struct s_sprite
{
	t_img			*imgs;
	int				count;
	int				actual_frame;
}					t_sprite;

typedef struct s_textures
{
	t_img			pl_u;
	t_img			pl_d;
	t_img			pl_r;
	t_img			pl_l;
	t_img			wall;
	t_img			free;
	t_img			exit_op;
	t_img			exit_cl;
	t_sprite		coll;
}					t_textures;

typedef struct s_game
{
	t_mapdata		*map;
	t_player		pl;
	t_mlx_img		grid;
	t_mlx_img		sprites;
	t_inputmanager	inputs;
	t_textures		tex;
	t_vector2		resolution;
	t_coll			*colls;
	t_vector2		c_size;
	int				isInit;
	void			*mlx;
	void			*window;
}					t_game;

int					map_init(t_game *gm, char *path);
void				free_map(t_mapdata *mp);
int					check_map_error(t_mapdata *mf, t_vector2 *size, char *path);
int					precheck(char *path);
int					acquire_map(t_mapdata *md, t_vector2 *size, char *path);
int					assign_map_positions(t_mapdata *map);
int					is_valid_char(char c);
//Errors Debug Function
int					alert_map_error(t_mapdata *map);
int					alert_char_issue(t_vector2 pos, int err);
int					alert_map_issue(int err);
//Vector2 Functions
t_vector2			create_vector2(int x, int y);
int					isnull_vector2(t_vector2 vector);

#endif