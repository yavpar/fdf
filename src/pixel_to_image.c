/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:17:38 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/04 16:23:26 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	THIS FUNCUTION FILLS ONE ADDRESS OF THE BUFFER IMAGE WITH THE PIXEL */
void	pixel_put_to_image(t_fdf *fdf, int x, int y, int pixel)
{
	int	i;

	i = (x * (fdf->bpp / 8)) + (y * fdf->line_len);
	if (i >= 0 && i < (WIDTH * HEIGHT * (fdf->bpp / 8)))
		*(unsigned int *)(fdf->img_data + i) = pixel;
}

/*	THIS FUNCUTION FILLS THE WINDOW WITH BLACK COLOR	*/
void	clear_image(t_fdf *fdf)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			{
				i = (x * (fdf->bpp / 8)) + (fdf->line_len * y);
				if (i >= 0 && i < (WIDTH * HEIGHT * (fdf->bpp / 8)))
					*(unsigned int *)(fdf->img_data + i) = 0;
			}
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}
