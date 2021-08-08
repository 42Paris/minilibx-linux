/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2001/12/11 15:25:27 by olivier cro       #+#    #+#             */
/*   Updated: 2021/08/05 23:35:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "mlx_rgb_lookup.h"
#include "t_img.h"

char	*mlx_int_static_line(char **xpm_data, int *pos, int size);
void	*mlx_int_parse_xpm(t_xvar *xvar, void *info, int info_size,
			char *(*f)());

void	*mlx_xpm_to_image(t_xvar *xvar, char **xpm_data,
	int *width, int *height)
{
	t_img	*img;

	img = mlx_int_parse_xpm(xvar, xpm_data, 0, mlx_int_static_line);
	if (img)
	{
		*width = img->width;
		*height = img->height;
	}
	return (img);
}
