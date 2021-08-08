/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 02:25:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 01:57:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

int	mlx_get_screen_size(void *mlx_ptr, int *size_x, int *size_y)
{
	XWindowAttributes	xwAttr;
	Status				ret;
	t_xvar				*xvar;

	xvar = mlx_ptr;
	ret = XGetWindowAttributes(xvar->display, xvar->root, &xwAttr);
	(*size_x) = xwAttr.width;
	(*size_y) = xwAttr.height;
	return (ret);
}
