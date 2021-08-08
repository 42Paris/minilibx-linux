/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_static_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:26:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 17:49:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

unsigned int	strlcpy_is_not_posix(char *dest, char *src, unsigned int size);

char	*mlx_int_static_line(char **xpm_data, int *pos, int size)
{
	static char	*copy = 0;
	static int	len = 0;
	int			len2;
	char		*str;

	(void)size;
	str = xpm_data[(*pos)++];
	len2 = strlen(str);
	if (len2 > len)
	{
		if (copy)
			free(copy);
		copy = malloc(len2 + 1);
		if (!copy)
			return (NULL);
		len = len2;
	}
	strlcpy_is_not_posix(copy, str, len2);
	return (copy);
}
