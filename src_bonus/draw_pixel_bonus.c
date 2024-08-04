/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:56:18 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/02 14:36:32 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THIS FUNCUTION FILLS THE BUFFER WITH THE PIXELS	*/
void pixel_put_to_image(t_fdf *fdf, int x, int y, int color)
{
	int i;
	
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * (fdf->bpp / 8)) + (y * fdf->line_len);
		if (i >= 0 && i < (WIDTH * HEIGHT * (fdf->bpp / 8)))
		{			
			fdf->img_data[i] = color & 0xFF;
			fdf->img_data[++i] = (color >> 8) & 0xFF;
			fdf->img_data[++i] = (color >> 16) & 0xFF;
		}
	}
}

/*	THIS FUNCUTION FILLS THE BUFFER WITH BLACK COLOR	*/
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
					*(unsigned int *)(fdf->img_data + i) = BLACK;
			}
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}
