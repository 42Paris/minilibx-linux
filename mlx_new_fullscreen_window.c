/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_fullscreen_window.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:03:21 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/18 16:23:27 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** We do not use White/BlackPixel macro, TrueColor Visual make sure
** 0 is black & -1 is white
**
** With mlx_int_wait_first_expose, no flush is needed.
*/

#include "mlx_int.h"

void	*mlx_new_fullscreen_window(t_xvar *xvar, int *size_x, int *size_y,
		char *title)
{
	t_win_list				*new_win;
	XSetWindowAttributes	xswa;
	XGCValues				xgcv;

	xswa.background_pixel = 0;
	xswa.border_pixel = -1;
	xswa.colormap = xvar->cmap;
	xswa.override_redirect = 1;
	/*
	xswa.event_mask = ButtonPressMask | ButtonReleaseMask | ExposureMask |
		KeyPressMask | KeyReleaseMask | StructureNotifyMask;
	*/
	/* xswa.event_mask = ExposureMask; */
	xswa.event_mask = 0xFFFFFF; /* all events */

	if (!(new_win = malloc(sizeof(*new_win))))
		return ((void *)0);
	mlx_get_screen_size(xvar, size_x, size_y);
	new_win->window = XCreateWindow(xvar->display, xvar->root, 0, 0, *size_x,
			*size_y, 0, CopyFromParent, InputOutput, xvar->visual,
			CWEventMask | CWBackPixel | CWBorderPixel | CWColormap | CWOverrideRedirect,
			&xswa);

	mlx_int_anti_resize_win(xvar, new_win->window, *size_x, *size_y);
	XStoreName(xvar->display, new_win->window, title);
	XSetWMProtocols(xvar->display, new_win->window, &(xvar->wm_delete_window),
			1);

	xgcv.foreground = -1;
	xgcv.function = GXcopy;
	xgcv.plane_mask = AllPlanes;

	new_win->gc = XCreateGC(xvar->display, new_win->window,
			GCFunction | GCPlaneMask | GCForeground, &xgcv);
	new_win->next = xvar->win_list;
	xvar->win_list = new_win;
	/*
	new_win->mouse_hook = mlx_int_do_nothing;
	new_win->key_hook = mlx_int_do_nothing;
	new_win->expose_hook = mlx_int_do_nothing;
	*/

	bzero(&(new_win->hooks), sizeof(new_win->hooks));
	XMapRaised(xvar->display, new_win->window);
	mlx_int_wait_first_expose(xvar, new_win->window);

	return (new_win);
}
