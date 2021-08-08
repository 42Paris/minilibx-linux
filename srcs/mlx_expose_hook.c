/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_expose_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/08/03 01:48:21 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/07/28 02:45:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

void	mlx_expose_hook(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[Expose].hook = funct;
	win->hooks[Expose].param = param;
	win->hooks[Expose].mask = ExposureMask;
}
