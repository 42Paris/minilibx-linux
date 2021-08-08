/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_xpm_file_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:39:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:35:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

void	mlx_int_file_get_rid_comment(char *ptr, int size);
char	*mlx_int_get_line(char *ptr, int *pos, int size);
void	*mlx_int_parse_xpm(t_xvar *xvar, void *info, int info_size,
			char *(*f)());

static void	*mlx_close_n_quit(int fd)
{
	close (fd);
	return (NULL);
}

void	*mlx_xpm_file_to_image(t_xvar *xvar, char *file,
	int *width, int *height)
{
	int		fd;
	int		size;
	char	*ptr;
	t_img	*img;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	size = lseek(fd, 0, SEEK_END);
	if (size == -1)
		return (mlx_close_n_quit(fd));
	ptr = mmap(0, size, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd, 0);
	if (ptr == (void *)MAP_FAILED)
		return (mlx_close_n_quit(fd));
	mlx_int_file_get_rid_comment(ptr, size);
	img = mlx_int_parse_xpm(xvar, ptr, size, mlx_int_get_line);
	if (img)
	{
		*width = img->width;
		*height = img->height;
	}
	munmap(ptr, size);
	close(fd);
	return (img);
}
