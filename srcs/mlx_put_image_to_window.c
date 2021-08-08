/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_image_to_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/14 15:55:49 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/08/05 23:36:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

void	mlx_put_image_to_window(t_xvar *xvar, t_win_list *win, t_img *img,
			int *xy)
{
	GC	gc;

	gc = win->gc;
	if (img->gc)
	{
		gc = img->gc;
		XSetClipOrigin(xvar->display, gc, xy[0], xy[1]);
	}
	if (img->type == MLX_TYPE_SHM)
		XShmPutImage(xvar->display, img->pix, win->gc, img->image, 0, 0, 0, 0,
			img->width, img->height, False);
	if (img->type == MLX_TYPE_XIMAGE)
		XPutImage(xvar->display, img->pix, win->gc, img->image, 0, 0, 0, 0,
			img->width, img->height);
	XCopyArea(xvar->display, img->pix, win->window, gc, 0, 0,
		img->width, img->height, xy[0], xy[1]);
	if (xvar->do_flush)
		XFlush(xvar->display);
}
