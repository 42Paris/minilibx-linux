/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_file_get_rid_comment.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:38:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/20 18:09:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"

void	mlx_int_file_get_rid_comment(char *ptr, int size)
{
	int	com_beg;
	int	com_end;

	com_beg = mlx_int_str_str_cote(ptr, "/*", size);
	while (com_beg != -1)
	{
		com_end = mlx_int_str_str(ptr + com_beg + 2, "*/", size - com_beg - 2);
		memset(ptr + com_beg, ' ', com_end + 4);
		com_beg = mlx_int_str_str_cote(ptr, "/*", size);
	}
	com_beg = mlx_int_str_str_cote(ptr, "//", size);
	while (com_beg != -1)
	{
		com_end = mlx_int_str_str(ptr + com_beg + 2, "\n", size - com_beg - 2);
		memset(ptr + com_beg, ' ', com_end + 3);
		com_beg = mlx_int_str_str_cote(ptr, "//", size);
	}
}
