/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_xpm_set_pixel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:32:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 18:18:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_zeta.h"

void	mlx_int_xpm_set_pixel(t_zeta zeta)
{
	int	dec;

	dec = zeta.opp;
	while (dec--)
	{
		if (zeta.img->image->byte_order)
			*(zeta.data + zeta.x * zeta.opp + dec) = zeta.col & 0xFF;
		else
			*(zeta.data + zeta.x * zeta.opp + zeta.opp - dec - 1)
				= zeta.col & 0xFF;
		zeta.col >>= 8;
	}
}
