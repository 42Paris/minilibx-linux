/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:50:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 17:06:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_zeta.h"

void	*mlx_return(t_xvar *xvar, t_zeta *zeta)
{
	if (zeta->colors)
		free(zeta->colors);
	if (zeta->tab)
		free(zeta->tab);
	zeta->tab = NULL;
	if (zeta->colors_direct)
		free(zeta->colors_direct);
	if (zeta->img)
	{
		XDestroyImage(zeta->img->image);
		XFreePixmap(xvar->display, zeta->img->pix);
		free(zeta->img);
	}
	return (NULL);
}
