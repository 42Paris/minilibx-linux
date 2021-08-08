/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:44:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:33:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

extern int	g_mlx_X_error;

void	set_val0(t_img *img, int const *whf)
{
	img->width = whf[0];
	img->height = whf[1];
	img->size_line = img->image->bytes_per_line;
	img->bpp = img->image->bits_per_pixel;
	img->shm.shmid = shmget(IPC_PRIVATE, (whf[0] + 32) * whf[1] * 4,
			IPC_CREAT | 0777);
	img->format = whf[2];
}

void	set_val1(t_img *img)
{
	img->image->data = shmat(img->shm.shmid, 0, 0);
	img->shm.shmaddr = img->image->data;
	img->data = img->shm.shmaddr;
}

XErrorHandler	set_val2(t_img *img)
{
	img->shm.readOnly = False;
	g_mlx_X_error = 0;
	return (XSetErrorHandler(shm_att_pb));
}

void	set_val3(t_img *img, t_xvar *xvar, int const *whf)
{
	img->pix = XShmCreatePixmap(xvar->display, xvar->root, img->shm.shmaddr,
			&(img->shm), whf[0], whf[1], xvar->depth);
	img->type = MLX_TYPE_SHM_PIXMAP;
}

void	set_val4(t_img *img, t_xvar *xvar, int const *whf)
{
	img->pix = XCreatePixmap(xvar->display, xvar->root,
			whf[0], whf[1], xvar->depth);
	img->type = MLX_TYPE_SHM;
}
