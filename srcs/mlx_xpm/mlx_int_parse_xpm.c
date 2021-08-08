/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_parse_xpm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:35:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 20:01:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zeta.h"

void	*mlx_return(t_xvar *xvar, t_zeta *zeta);
void	mlx_int_xpm_set_pixel(t_zeta zeta);
int		mlx_int_get_col_name(char *str, int size);
int		mlx_int_get_text_rgb(char *name, char *end);
int		part0(t_zeta *zeta);
int		part1(t_zeta *zeta);
int		part2(t_zeta *zeta);
int		part3(t_zeta *zeta);

void	*mlx_int_parse_xpm(t_xvar *xvar, void *info, int info_size,
	char *(*f)())
{
	t_zeta	zeta;

	zeta.info = info;
	zeta.info_size = info_size;
	zeta.f = f;
	if (part0(&zeta) == -1)
		return (mlx_return(xvar, &zeta));
	if (part1(&zeta) == -1)
		return (mlx_return(xvar, &zeta));
	if (part2(&zeta) == -1)
		return (mlx_return(xvar, &zeta));
	if (part3(&zeta) == -1)
		return (mlx_return(xvar, &zeta));
	if (zeta.colors)
		free(zeta.colors);
	if (zeta.colors_direct)
		free(zeta.colors_direct);
	return (zeta.img);
}
