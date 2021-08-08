/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_str_to_wordtab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2000/09/13 11:36:09 by Charlie Roo       #+#    #+#             */
/*   Updated: 2021/08/04 22:51:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

int	mlx_int_str_str(char *str, char *find, int len)
{
	int		len_f;
	int		pos;
	char	*s;
	char	*f;

	len_f = strlen(find);
	if (len_f > len)
		return (-1);
	pos = 0;
	while (*(str + len_f - 1))
	{
		s = str;
		f = find;
		while (*(f++) == *(s++))
			if (!*f)
				return (pos);
		str ++;
		pos ++;
	}
	return (-1);
}

int	mlx_int_str_str_cote(char *str, char *find, int len)
{
	int		i[3];
	char	*p[2];

	i[0] = strlen(find);
	if (i[0] > len)
		return (-1);
	i[1] = 0;
	i[2] = 0;
	while (*(str + i[0] - 1))
	{
		if (*str == '"')
			i[1] = !i[1];
		if (!i[1])
		{
			p[0] = str;
			p[1] = find;
			while (*(p[0]++) == *(p[1]++))
				if (!*p[1])
					return (i[2]);
		}
		++str;
		++i[2];
	}
	return (-1);
}

static char	**populate(char **tab, char *ptr, char const *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		tab[size++] = ptr;
		while (*s && *s != ' ' && *s != '\t')
			*ptr++ = *s++;
		*ptr++ = 0;
		while (*s && (*s == ' ' || *s == '\t'))
			++s;
	}
	return (tab);
}

char	**mlx_int_str_to_wordtab(char *s)
{
	char	**tab;
	size_t	size;
	size_t	len;

	size = 0;
	len = 0;
	while (*s && (*s == ' ' || *s == '\t'))
		++s;
	while (s[len])
	{
		if (s[len] != ' ' && s[len] != '\t'
			&& (!len || s[len - 1] == ' ' || s[len - 1] == '\t'))
			++size;
		++len;
	}
	tab = malloc((size + 1) * sizeof(char *) + (len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[size] = NULL;
	return (populate(tab, (char *)(tab + size + 1), s));
}
