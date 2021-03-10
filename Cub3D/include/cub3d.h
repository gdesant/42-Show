/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/minilibx_linux/mlx.h"
# include "../lib/libcustom/include/parse_map.h"
# include <X11/X.h>

# define CELL_SIZE 64
# define TEX_SIZE 64
# define SPRITE_HEIGHT 32
# define SPRITE_LENGHT 32

# define FOV 90
# define SPEED 10
# define RAY_DISTANCE 1000
# define TN 0.06

# define KEY_PRESS		2
# define KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17

# define KEY_Z		119
# define KEY_S		115
# define KEY_Q		97
# define KEY_D		100
# define KEY_A		65361
# define KEY_E		65363
# define KEY_R		114
# define KEY_ESC	65307

typedef struct	s_wall
{
	int			lenght;
	int			height;
	int			startx;
	int			starty;
	double		dist;
	int			i;
}				t_wall;

int				raycast (t_game *gm);
int				init_rays (t_game *gm);
unsigned int	ray_side(t_game *gm, int i, double x);
int				ho_check(t_game *gm, int x, double *tempx, double *tempy);
int				vo_check(t_game *gm, int x, double *tempx, double *tempy);
int				fixang(int a);
void			put_pixel_to_img(t_mlx_img *img, int x, int y, int clr);
double			alwayspos(double x);
int				getclr(t_color clr);
int				clean_exit(t_game *gm);
int				checkresutils(t_game *gm);
int				draw_walls(t_game *gm);
int				init_pl(t_game *gm);
void			init_tex(t_game *gm);
int				init_ang(t_game *gm);
void			turn_player(t_game *gm, int dir);
void			move_front(t_game *gm, int dir);
void			move_side(t_game *gm, int dir);
int				keys_handler(t_game *gm);
void			set_key(t_game *game, int key, int state);
int				on_pressed_event(int key, t_game *game);
int				on_released_event(int key, t_game *game);
void			print_sprites(t_game *gm);
int				count_case(t_game *gm, char c);
void			save_bmp(t_game *gm);
int				main_loop(t_game *gm);
int				end_game_loop(t_game *gm);
int				reset_game(t_game *gm);
int				game(t_game *gm);
void			init_end(t_game *gm);

#endif
