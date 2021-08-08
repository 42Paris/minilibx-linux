/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clean_quit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:20:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:32:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_int.h"
#include "t_img.h"

void	*mlx_clean_quit0(t_img *img)
{
	free(img);
	return (NULL);
}

void	*mlx_clean_quit1(t_img *img)
{
	XDestroyImage(img->image);
	free(img);
	return (NULL);
}

void	*mlx_clean_quit2(t_img *img)
{
	shmctl(img->shm.shmid, IPC_RMID, 0);
	XDestroyImage(img->image);
	free(img);
	return (NULL);
}

void	*mlx_clean_quit3(t_img *img, int (*save_handler)())
{
	XSetErrorHandler(save_handler);
	shmdt(img->data);
	shmctl(img->shm.shmid, IPC_RMID, 0);
	XDestroyImage(img->image);
	free(img);
	return (NULL);
}
