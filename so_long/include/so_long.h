/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:55:19 by gde-sant          #+#    #+#             */
/*   Updated: 2020/01/17 16:10:54 by gde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx_linux/mlx.h"
# include "../lib/libcustom/include/parse_map.h"
# include <X11/X.h>

# define CELL_SIZE 32

# define MAP_EXTENSION ".ber"

# define PATH_TEX_FREE "./textures/free.xpm"
# define PATH_TEX_OCC "./textures/occ.xpm"

# define PATH_TEX_COLL_0 "./textures/coin/coin0.xpm"
# define PATH_TEX_COLL_1 "./textures/coin/coin1.xpm"
# define PATH_TEX_COLL_2 "./textures/coin/coin2.xpm"
# define PATH_TEX_COLL_3 "./textures/coin/coin3.xpm"
# define PATH_TEX_COLL_4 "./textures/coin/coin4.xpm"
# define PATH_TEX_COLL_5 "./textures/coin/coin5.xpm"

# define PATH_TEX_EX_OP "./textures/door_open.xpm"
# define PATH_TEX_EX_CL "./textures/door_close.xpm"

# define PATH_TEX_PL_U "./textures/player/up.xpm"
# define PATH_TEX_PL_D "./textures/player/down.xpm"
# define PATH_TEX_PL_R "./textures/player/right.xpm"
# define PATH_TEX_PL_L "./textures/player/left.xpm"

# define MOV_ERR_WA -1
# define MOV_ERR_DR -2
# define MOV_ERR_WD -3

# define MOVE_UP 1
# define MOVE_DOWN 2
# define MOVE_RIGHT 3
# define MOVE_LEFT 4

# define SPEED 10

# define KEY_PRESS		2
# define KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17

# define KEY_W		119
# define KEY_S		115
# define KEY_D		100
# define KEY_A		97
# define KEY_ESC	65307

//init
void				init_so_long(t_game *gm);

//debug
int					maincheckerror(int argc, char **argv, int *fd);
int					debug_mov_error(t_vector2 new_pos, int err);
int					clean_exit(t_game *gm);
void				debug_win(int win, int score);

//utils
int					ft_strendwith(char *line, char *end);
int					checkresutils(t_game *gm);
t_mlx_img			create_image(t_game *gm, int lenght, int height);
t_img				init_xpm(t_game *gm, char *path);
int					get_col_i(t_game *gm, t_vector2 pos);

//printer
int					printer(t_game *gm);
int					print_case_pixel(t_game *gm, t_vector2 block,
						t_mlx_img *screen, t_img img);

//printer - utils
void				put_pixel_to_img(t_mlx_img *img, int x, int y,
						unsigned int clr);
int					getclr(t_color clr);
t_color				create_color(int r, int g, int b, int s);
t_coll				create_coll(t_vector2 pos);
void				print_coll(t_game *gm);

//inputs
int					keys_handler(t_game *gm);
void				set_key(t_game *gm, int key, int state);
int					on_pressed_event(int key, t_game *gm);
int					on_released_event(int key, t_game *gm);

//movement
int					move_to_col(t_game *gm, t_vector2 pos);
int					move_to(t_game *gm, t_vector2 direction, int *key);

#endif
