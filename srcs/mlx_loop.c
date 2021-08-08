/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/02 18:58:11 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/08/07 09:53:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "mlx_event_lookup.h"

static int	win_count(t_xvar *xvar)
{
	int			i;
	t_win_list	*win;

	i = 0;
	win = xvar->win_list;
	while (win)
	{
		win = win->next;
		++i;
	}
	return (i);
}

int	mlx_loop_end(t_xvar *xvar)
{
	xvar->end_loop = 1;
	return (1);
}

int	mlx_loop(t_xvar *xvar)
{
	XEvent		ev;
	t_win_list	*win;

	mlx_int_set_win_event_mask(xvar);
	xvar->do_flush = 0;
	while (win_count(xvar) && !xvar->end_loop)
	{
		while (!xvar->end_loop && (!xvar->loop_hook || XPending(xvar->display)))
		{
			XNextEvent(xvar->display, &ev);
			win = xvar->win_list;
			while (win && (win->window != ev.xany.window))
				win = win->next;
			if (win && ev.type == ClientMessage
				&& ev.xclient.message_type == xvar->wm_protocols
				&& (Atom)ev.xclient.data.l[0] == xvar->wm_delete_window
				&& win->hooks[DestroyNotify].hook)
				win->hooks[DestroyNotify].hook(win->hooks[DestroyNotify].param);
			if (win && ev.type < MLX_MAX_EVENT && win->hooks[ev.type].hook)
				g_mlx_int_param_event[ev.type](xvar, &ev, win);
		}
		XSync(xvar->display, False);
		xvar->loop_hook(xvar->loop_param);
	}
	return (0);
}
