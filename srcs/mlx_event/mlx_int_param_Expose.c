/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_param_Expose.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:55:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/04 20:55:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	(void)xvar;
	if (!ev->xexpose.count)
		win->hooks[Expose].hook(win->hooks[Expose].param);
}
