/*
** mlx_loop.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Wed Aug  2 18:58:11 2000 Charlie Root
** Last update Fri Sep 30 14:47:41 2005 Olivier Crouzet
*/


#include	"mlx_int.h"

extern int	(*(mlx_int_param_event[]))();

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

int			mlx_loop(t_xvar *xvar)
{
	XEvent		ev;
	t_win_list	*win;
	int 		end_loop;

	mlx_int_set_win_event_mask(xvar);
	xvar->do_flush = 0;
	end_loop = 0;
	while (win_count(xvar))
	{
		while (!xvar->loop_hook || XPending(xvar->display))
		{
			XNextEvent(xvar->display,&ev);
			win = xvar->win_list;
			while (win && (win->window!=ev.xany.window))
				win = win->next;
			if (win && ev.type < MLX_MAX_EVENT && win->hooks[ev.type].hook)
			{
				end_loop = (ev.type == ClientMessage
							&& (Atom)ev.xclient.data.l[0] == xvar->wm_delete_window)
						   || ev.xkey.keycode == 9;
				mlx_int_param_event[ev.type](xvar, &ev, win);
				if (end_loop)
					break;
			}
		}
		if (!end_loop)
		{
			xvar->loop_hook(xvar->loop_param);
			XSync(xvar->display, False);
		}
		else
			break ;
	}
	return (0);
}
