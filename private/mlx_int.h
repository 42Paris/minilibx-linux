/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/07/31 16:45:48 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/08/05 23:26:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Internal settings for MiniLibX
*/

#ifndef MLX_INT_H

# define MLX_INT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>
# include "t_xvar.h"
/* #include	<X11/xpm.h> */

# define MLX_TYPE_SHM_PIXMAP 3
# define MLX_TYPE_SHM 2
# define MLX_TYPE_XIMAGE 1

# define ENV_DISPLAY "DISPLAY"
# define LOCALHOST "localhost"
# define ERR_NO_TRUECOLOR "MinilibX Error : No TrueColor Visual available.\n"
# define WARN_SHM_ATTACH "MinilibX Warning : \
X server can't attach shared memory.\n"

struct	s_col_name
{
	char	*name;
	int		color;
};

void			mlx_int_do_nothing(void *param);
int				mlx_get_color_value(t_xvar *xvar, int color);
int				mlx_int_get_good_color(t_xvar *xvar, int color);
int				mlx_int_find_in_pcm(void);
void			mlx_int_anti_resize_win(t_xvar *xvar, Window win, int w, int h);
void			mlx_int_wait_first_expose(t_xvar *xvar, Window win);
void			mlx_int_rgb_conversion(t_xvar *xvar);
void			mlx_int_deal_shm(t_xvar *xvar);
void			*mlx_int_new_xshm_image(t_xvar *xvar, int width, int height,
					int format);
char			**mlx_int_str_to_wordtab(char *s);
void			*mlx_new_image(t_xvar *xvar, int width, int height);
int				shm_att_pb(Display *d, XErrorEvent *ev);
int				mlx_int_get_visual(t_xvar *xvar);
void			mlx_int_set_win_event_mask(t_xvar *xvar);
int				mlx_int_str_str_cote(char *str, char *find, int len);
int				mlx_int_str_str(char *str, char *find, int len);

#endif
