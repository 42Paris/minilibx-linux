/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event_lookup.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:59:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/07 09:57:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_EVENT_LOOKUP_H
# define MLX_EVENT_LOOKUP_H

# include "mlx_int.h"

void	mlx_int_param_undef(t_xvar *xvar, XEvent *ev, t_win_list *win);
void	mlx_int_param_KeyPress(t_xvar *xvar, XEvent *ev, t_win_list *win);
void	mlx_int_param_KeyRelease(t_xvar *xvar, XEvent *ev, t_win_list *win);
void	mlx_int_param_ButtonPress(t_xvar *xvar, XEvent *ev, t_win_list *win);
void	mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win);
void	mlx_int_param_MotionNotify(t_xvar *xvar, XEvent *ev, t_win_list *win);
void	mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win);
void	mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_win_list *win);

void	(*(g_mlx_int_param_event[]))() =
{
	mlx_int_param_undef,
	mlx_int_param_undef,
	mlx_int_param_KeyPress,
	mlx_int_param_KeyRelease,
	mlx_int_param_ButtonPress,
	mlx_int_param_ButtonRelease,
	mlx_int_param_MotionNotify,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_Expose,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic
};

#endif
