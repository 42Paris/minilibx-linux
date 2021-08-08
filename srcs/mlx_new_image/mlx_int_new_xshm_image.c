/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_new_xshm_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:00:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:33:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

void			*mlx_clean_quit0(t_img *img);
void			*mlx_clean_quit1(t_img *img);
void			*mlx_clean_quit2(t_img *img);
void			*mlx_clean_quit3(t_img *img, int (*save_handler)());

void			set_val0(t_img *img, int const *whf);
void			set_val1(t_img *img);
XErrorHandler	set_val2(t_img *img);
void			set_val3(t_img *img, t_xvar *xvar, int const *whf);
void			set_val4(t_img *img, t_xvar *xvar, int const *whf);
/*
** To handle X errors
*/

#define	X_SHMATTACH	1

int	g_mlx_X_error;

int	shm_att_pb(Display *d, XErrorEvent *ev)
{
	(void)d;
	if (ev->request_code == 146 && ev->minor_code == X_SHMATTACH)
		write(2, WARN_SHM_ATTACH, strlen(WARN_SHM_ATTACH));
	g_mlx_X_error = 1;
	return (0);
}

static void	*part_2(t_xvar *xvar, t_img *img, int const *whf,
	int (*save_handler)())
{
	if (!XShmAttach(xvar->display, &(img->shm))
		|| 0 & XSync(xvar->display, False) || g_mlx_X_error)
		return (mlx_clean_quit3(img, save_handler));
	XSetErrorHandler(save_handler);
	shmctl(img->shm.shmid, IPC_RMID, 0);
	if (xvar->pshm_format == whf[2])
		set_val3(img, xvar, whf);
	else
		set_val4(img, xvar, whf);
	if (xvar->do_flush)
		XFlush(xvar->display);
	return (img);
}

void	*mlx_int_new_xshm_image(t_xvar *xvar, int width, int height, int format)
{
	t_img		*img;
	int			(*save_handler)();
	int const	whf[3] = {width, height, format};

	img = malloc(sizeof(*img));
	if (!img)
		return (NULL);
	bzero(img, sizeof(*img));
	img->data = 0;
	img->image = XShmCreateImage(xvar->display, xvar->visual, xvar->depth,
			format, img->data, &(img->shm), width, height);
	if (!img->image)
		return (mlx_clean_quit0(img));
	set_val0(img, whf);
	if (img->shm.shmid == -1)
		return (mlx_clean_quit1(img));
	set_val1(img);
	if (img->data == (void *)(-1))
		return (mlx_clean_quit2(img));
	save_handler = set_val2(img);
	return (part_2(xvar, img, whf, save_handler));
}
