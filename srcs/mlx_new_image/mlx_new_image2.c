/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:53:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:33:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format);

void	*mlx_new_image2(t_xvar *xvar, int width, int height)
{
	t_img	*img;

	if (xvar->use_xshm)
	{
		img = mlx_int_new_xshm_image(xvar, width, height, XYPixmap);
		if (img)
			return (img);
	}
	return (mlx_int_new_image(xvar, width, height, XYPixmap));
}
