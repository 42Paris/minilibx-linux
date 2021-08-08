/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/07/31 17:29:02 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/08/05 01:13:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** We do not use White/BlackPixel macro, TrueColor Visual make sure
** 0 is black & -1 is white
**
** With mlx_int_wait_first_expose, no flush is needed.
*/

#include	"mlx_int.h"

static void	init_xswa(XSetWindowAttributes *xswa, t_xvar *xvar)
{
	xswa->background_pixel = 0;
	xswa->border_pixel = -1;
	xswa->colormap = xvar->cmap;
	xswa->event_mask = 0xFFFFFF;
}

static void	init_xgcv(XGCValues *xgcv)
{
	xgcv->foreground = -1;
	xgcv->function = GXcopy;
	xgcv->plane_mask = AllPlanes;
}

void	*mlx_new_window(t_xvar *xvar, int size_x, int size_y, char *title)
{
	t_win_list				*new_win;
	XSetWindowAttributes	xswa;
	XGCValues				xgcv;

	init_xswa(&xswa, xvar);
	new_win = malloc(sizeof(*new_win));
	if (!new_win)
		return (NULL);
	new_win->window = XCreateWindow(xvar->display, xvar->root, 0, 0, size_x,
			size_y, 0, CopyFromParent, InputOutput, xvar->visual,
			CWEventMask | CWBackPixel | CWBorderPixel | CWColormap, &xswa);
	mlx_int_anti_resize_win(xvar, new_win->window, size_x, size_y);
	XStoreName(xvar->display, new_win->window, title);
	XSetWMProtocols(xvar->display, new_win->window, &(xvar->wm_delete_window),
		1);
	init_xgcv(&xgcv);
	new_win->gc = XCreateGC(xvar->display, new_win->window,
			GCFunction | GCPlaneMask | GCForeground, &xgcv);
	new_win->next = xvar->win_list;
	xvar->win_list = new_win;
	bzero(&(new_win->hooks), sizeof(new_win->hooks));
	XMapRaised(xvar->display, new_win->window);
	mlx_int_wait_first_expose(xvar, new_win->window);
	return (new_win);
}
