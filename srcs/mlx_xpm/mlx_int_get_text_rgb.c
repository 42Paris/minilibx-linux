/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_get_text_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:29:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 17:45:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_rgb_lookup.h"

int	mlx_int_get_text_rgb(char *name, char *end)
{
	int		i;
	char	buff[64];

	if (*name == '#')
		return (strtol(name + 1, 0, 16));
	if (end)
	{
		snprintf(buff, 64, "%s %s", name, end);
		name = buff;
	}
	i = 0;
	while (g_mlx_col_name[i].name)
	{
		if (!strcasecmp(g_mlx_col_name[i].name, name))
			return (g_mlx_col_name[i].color);
		++i;
	}
	return (0);
}
