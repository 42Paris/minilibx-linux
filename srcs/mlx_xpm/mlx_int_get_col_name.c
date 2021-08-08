/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_get_col_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:27:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 17:28:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	mlx_int_get_col_name(char *str, int size)
{
	int	result;

	result = 0;
	while (size--)
		result = (result << 8) + *(str++);
	return (result);
}
