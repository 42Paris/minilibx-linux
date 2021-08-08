/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_get_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:23:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 17:45:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

char	*mlx_int_get_line(char *ptr, int *pos, int size)
{
	int	pos2;
	int	pos3;
	int	pos4;

	pos2 = mlx_int_str_str(ptr + *pos, "\"", size - *pos);
	if (pos2 == -1)
		return (NULL);
	pos3 = mlx_int_str_str(ptr + *pos + pos2 + 1, "\"", size - *pos - pos2 - 1);
	if (pos3 == -1)
		return (NULL);
	*(ptr + *pos + pos2) = 0;
	*(ptr + *pos + pos2 + 1 + pos3) = 0;
	pos4 = *pos + pos2 + 1;
	*pos += pos2 + pos3 + 2;
	return (ptr + pos4);
}
