/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/07/31 19:01:33 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/08/08 08:12:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

void	mlx_pixel_put(t_xvar *xvar, t_win_list *win, int *xyc)
{
	XGCValues	xgcv;

	xgcv.foreground = mlx_int_get_good_color(xvar, xyc[2]);
	XChangeGC(xvar->display, win->gc, GCForeground, &xgcv);
	XDrawPoint(xvar->display, win->window, win->gc, xyc[0], xyc[1]);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
