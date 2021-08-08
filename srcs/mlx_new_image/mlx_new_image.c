/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/14 15:29:14 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/08/05 23:33:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

void	*mlx_int_new_xshm_image(t_xvar *xvar, int width, int height,
			int format);
void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format);

void	*mlx_new_image(t_xvar *xvar, int width, int height)
{
	t_img	*img;

	if (xvar->use_xshm)
	{
		img = mlx_int_new_xshm_image(xvar, width, height, ZPixmap);
		if (img)
			return (img);
	}
	return (mlx_int_new_image(xvar, width, height, ZPixmap));
}
