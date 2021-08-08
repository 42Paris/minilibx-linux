/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_new_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:55:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:32:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

static void	set_val(t_img *img, t_xvar *xvar, int width, int height)
{
	img->gc = 0;
	img->size_line = img->image->bytes_per_line;
	img->bpp = img->image->bits_per_pixel;
	img->width = width;
	img->height = height;
	img->pix = XCreatePixmap(xvar->display, xvar->root, width, height,
			xvar->depth);
	img->type = MLX_TYPE_XIMAGE;
}

void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	if (!img)
		return (NULL);
	img->data = malloc((width + 32) * height * 4);
	if (!img->data)
	{
		free(img);
		return (NULL);
	}
	bzero(img->data, (width + 32) * height * 4);
	img->image = XCreateImage(xvar->display, xvar->visual, xvar->depth, format,
			0, img->data, width, height, 32, 0);
	if (!img->image)
	{
		free(img->data);
		free(img);
		return (NULL);
	}
	set_val(img, xvar, width, height);
	img->format = format;
	if (xvar->do_flush)
		XFlush(xvar->display);
	return (img);
}
