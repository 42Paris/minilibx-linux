/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_file_get_rid_comment.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:38:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 17:54:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_int_file_get_rid_comment(char *ptr, int size)
{
	int	com_begin;
	int	com_end;

	com_begin = mlx_int_str_str_cote(ptr, "/*", size);
	while (com_begin != -1)
	{
		com_end = mlx_int_str_str(ptr + com_begin + 2, "*/",
				size - com_begin - 2);
		memset(ptr + com_begin, ' ', com_end + 4);
	}
	com_begin = mlx_int_str_str_cote(ptr, "//", size);
	while (com_begin != -1)
	{
		com_end = mlx_int_str_str(ptr + com_begin + 2, "\n",
				size - com_begin - 2);
		memset(ptr + com_begin, ' ', com_end + 3);
	}
}
