/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_param_ButtonRelease.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:51:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/04 20:52:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	win->hooks[ButtonRelease].hook(ev->xbutton.button,
		ev->xbutton.x,
		ev->xbutton.y,
		win->hooks[ButtonRelease].param);
}
