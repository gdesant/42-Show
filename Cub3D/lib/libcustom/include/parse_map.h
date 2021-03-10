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

typedef struct		s_inputmanager{
	int				z;
	int				q;
	int				s;
	int				d;
	int				a;
	int				e;
	int				esc;
	int				r;
}					t_inputmanager;

typedef struct		s_vector2{
	double			x;
	double			y;
}					t_vector2;

typedef struct		s_sprite{
	int				s;
	t_vector2		pos;
	double			d;
	int				ray;
}					t_sprite;

typedef struct		s_player{
	double			x;
	double			y;
	double			ang;
	double			roty;
	double			rotx;
	int				set;
	int				icount;
}					t_player;

typedef struct		s_mlx_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_mlx_img;

typedef struct		s_img
{
	char			*path;
	void			*img;
	int				fd;
	int				size;
	t_mlx_img		mimg;
}					t_img;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				s;
}					t_color;

typedef struct		s_reso
{
	int				x;
	int				y;
}					t_reso;

typedef struct		s_ray
{
	double			posx;
	double			posy;
	double			ang;
	double			rotx;
	double			roty;
	double			endx;
	double			endy;
	double			d;
	int				v;
	int				h;
}					t_ray;

typedef struct		s_map
{
	int				height;
	int				lenght;
	int				c;
	int				e;
	char			**maparray;
	t_mlx_img		img;
}					t_map;

typedef struct		s_textures
{
	t_img			no;
	t_img			so;
	t_img			ea;
	t_img			we;
	t_img			sprite;
}					t_textures;

typedef struct		s_mapfile
{
	t_reso			resolution;
	t_textures		tex;
	t_player		pl;
	t_color			roof_color;
	t_color			ground_color;
	t_map			map;
	int				error;
}					t_mapfile;

typedef struct		s_game{
	t_mapfile		*mf;
	t_player		pl;
	t_ray			*ray_array;
	t_mlx_img		screen;
	t_mlx_img		endimg;
	t_mlx_img		endtex;
	t_inputmanager	inputs;
	int				spritelen;
	int				ispritelen;
	t_sprite		*sprites;
	void			*mlx;
	void			*window;
}					t_game;

int					map_init(t_game *gm, char *path);

int					sep_chara(char *str, char *charstr);
int					word_lenght(char *str, char *charset);
int					word_count(char *str, char *charset);
char				*word_copy(char *src, int k);
char				**ft_split(char *str, char *charset);

int					parse_map(int fd, t_game *gm, int mapsize);
int					ismapline(char *line);
int					treatmapline(char *line, t_mapfile *mp);
int					treatsrcline(char *line, t_mapfile *mp);
int					getsrcfile(char *line, t_img *img);
int					getcolorfile(char *line, t_color *clr);
int					getresfile(char *line, t_reso *res);
void				initmp(t_mapfile *mp);

int					ft_strlen_nspace(char *line);
int					ft_stock_size(char **stock);

int					ft_ccmp(char temp, char *src);
size_t				ft_strlcpy(char *dst, const char *src, int size);
int					get_map_height(int fd);

int					free_map(t_mapfile *mf);
int					free_map_tex(t_mapfile *mf);
int					free_map_array(t_mapfile *mf);
int					clean_exit_map(t_mapfile *mf);

int					check_map_error(t_mapfile *map);
int					check_free_case(char c);
int					check_case(t_mapfile *mf, int x, int y);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					check_resolution(t_mapfile *map);
int					check_img(t_img *img, char *id);
int					check_map_colors(t_color *c, char *id);
int					check_maparray(t_mapfile *mf);

int					check_color_err(char **stock, t_color *clr);
int					check_line_error(char *file, t_mapfile *mp);
int					contain_digit(char *src);

#endif
