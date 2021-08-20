/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part0_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:39:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/20 20:07:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zeta.h"

void	mlx_int_xpm_set_pixel(t_zeta zeta);
int		mlx_int_get_col_name(char *str, int size);
int		spart0(t_zeta *zeta);
int		spart1(t_xvar *xvar, t_zeta *zeta);
void	spart2(t_zeta *zeta);

int	part0(t_zeta *zeta)
{
	printf("part0\n\tzeta->width: %d\n\tzeta->height: %d\n\n", zeta->width, zeta->height);
	zeta->line = zeta->f(zeta->info, &zeta->pos, zeta->info_size);
	if (!zeta->line)
		return (-1);
	zeta->tab = mlx_int_str_to_wordtab(zeta->line);
	if (!zeta->tab)
		return (-1);
	zeta->width = atoi(zeta->tab[0]);
	zeta->height = atoi(zeta->tab[1]);
	zeta->nc = atoi(zeta->tab[2]);
	zeta->cpp = atoi(zeta->tab[3]);
	if (!zeta->width || !zeta->height || !zeta->nc || !zeta->cpp)
		return (-1);
	free(zeta->tab);
	zeta->tab = NULL;
	zeta->method = 0;
	return (0);
}

int	part1(t_zeta *zeta)
{
	printf("part1\n\tzeta->width: %d\n\tzeta->height: %d\n\n", zeta->width, zeta->height);
	if (zeta->cpp <= 2)
	{
		zeta->method = 1;
		zeta->colors_direct = malloc(((zeta->cpp == 2) * 65536
					+ (zeta->cpp != 2) * 256) * sizeof(int));
		if (!zeta->colors_direct)
			return (-1);
	}
	else
	{
		zeta->colors = malloc(zeta->nc * sizeof(*zeta->colors));
		if (!zeta->colors)
			return (-1);
	}
	zeta->clip_data = 0;
	zeta->i = zeta->nc;
	return (0);
}

int	part2(t_zeta *zeta)
{
	printf("part2.0\n\tzeta->width: %d\n\tzeta->height: %d\n\n", zeta->width, zeta->height);
	while (zeta->i--)
		if (spart0(zeta) == -1)
			return (-1);
	printf("part2.1\n\tzeta->width: %d\n\tzeta->height: %d\n\n", zeta->width, zeta->height);
	return (0);
}

int	part3(t_xvar *xvar, t_zeta *zeta)
{
	// printf("part3\n\tzeta->width: %d\n\tzeta->height: %d\n\n", zeta->width, zeta->height); fflush(stdout);
	if (spart1(xvar, zeta) == -1)
		return (-1);
	while (zeta->i--)
	{
		zeta->line = zeta->f(zeta->info, &zeta->pos, zeta->info_size);
		if (!zeta->line)
			return (-1);
		zeta->x = 0;
		while (zeta->x < zeta->width)
			spart2(zeta);
		zeta->data += zeta->img->size_line;
	}
	return (0);
}
