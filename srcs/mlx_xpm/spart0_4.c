/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spart0_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:46:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/20 20:38:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zeta.h"

void	mlx_int_xpm_set_pixel(t_zeta zeta);
int		mlx_int_get_text_rgb(char *name, char *end);
int		mlx_int_get_col_name(char *str, int size);

int	spart0(t_zeta *zeta)
{
	zeta->line = zeta->f(zeta->info, &zeta->pos, zeta->info_size);
	if (!zeta->line)
		return (-1);
	zeta->tab = mlx_int_str_to_wordtab(zeta->line + zeta->cpp);
	if (!zeta->tab)
		return (-1);
	zeta->j = 0;
	while (zeta->tab[zeta->j] && strcmp(zeta->tab[zeta->j], "c"))
		++zeta->j;
	if (!zeta->tab[zeta->j])
		return (-1);
	zeta->rgb_col
		= mlx_int_get_text_rgb(zeta->tab[zeta->j], zeta->tab[zeta->j + 1]);
	if (zeta->method)
		zeta->colors_direct[mlx_int_get_col_name(zeta->line, zeta->cpp)]
			= zeta->rgb_col;
	else
	{
		zeta->colors[zeta->i].name
			= mlx_int_get_col_name(zeta->line, zeta->cpp);
		zeta->colors[zeta->i].col = zeta->rgb_col;
	}
	free(zeta->tab);
	zeta->tab = NULL;
	return (0);
}

int	spart1(t_xvar *xvar, t_zeta *zeta)
{
	zeta->img = mlx_new_image(xvar, zeta->width, zeta->height);
	if (!zeta->img)
		return (-1);
	zeta->opp = zeta->img->bpp / 8;
	zeta->i = zeta->height;
	zeta->data = zeta->img->data;
	return (0);
}

void	spart2(t_zeta *zeta)
{
	zeta->col = 0;
	zeta->col_name
		= mlx_int_get_col_name(zeta->line + zeta->cpp * zeta->x, zeta->cpp);
	if (zeta->method)
		zeta->col = zeta->colors_direct[zeta->col_name];
	else
	{
		zeta->j = zeta->nc;
		while (zeta->j--)
		{
			if (zeta->colors[zeta->j].name == zeta->col_name)
			{
				zeta->col = zeta->colors[zeta->j].col;
				zeta->j = 0;
			}
		}
	}
	if (zeta->col == -1)
		zeta->col = 0xFF000000;
	mlx_int_xpm_set_pixel(*zeta);
	++zeta->x;
}
