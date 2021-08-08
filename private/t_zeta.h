/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_zeta.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:59:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:34:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ZETA_H
# define T_ZETA_H

# include "mlx_int.h"
# include "t_img.h"
# include "t_xpm_col.h"

typedef struct s_zeta	t_zeta;

struct s_zeta
{
	int			pos;
	char		*line;
	char		**tab;
	char		*data;
	char		*clip_data;
	int			nc;
	int			opp;
	int			cpp;
	int			col;
	int			rgb_col;
	int			col_name;
	int			method;
	int			x;
	int			i;
	int			j;
	t_img		*img;
	t_xpm_col	*colors;
	int			*colors_direct;
	int			width;
	int			height;
	XImage		*clip_img;
	XGCValues	xgcv;
	Pixmap		clip_pix;
	void		*info;
	int			info_size;
	char		*(*f)();
};

#endif
