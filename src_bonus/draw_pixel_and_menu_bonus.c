/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_and_menu_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:56:18 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/09 17:28:10 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THIS FUNCUTION FILLS THE BUFFER WITH THE PIXELS	*/
void	pixel_put_to_image(t_fdf *fdf, int x, int y, int color)
{
	int	i;

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
					*(unsigned int *)(fdf->img_data + i) = 0;
			}
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}

static void	draw_menu_plus(void *mlx, void *win, int y)
{
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Top view:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "t key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Front view:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "f key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Left view:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "l key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Isometric view:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "i key");
}

/*	THIS FUNCION SHOWS INFORMATATION ABOUT THE PROGRAM NAME AND				*/
/*	ALL THE FUNCTIONALITIES AVAIBLES IN ORDER TO INTERACT WITH THE IMAGE	*/
void	draw_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->mlx_win;
	mlx_string_put(mlx, win, 40, y += 20, WHITE, "Press the following keys:");
	mlx_string_put(mlx, win, 15, y += 50, TEXT, "Zoom:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, " + / - key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Pad +/-:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "8 / 2 key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Move:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Up arrow key");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Down arrow key");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Left arrow key");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Right arrow  key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "r key and then for:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Z-Axis: Key 4 or 6");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Y-Axis: Key 7 or 3");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Z-Axis: Key 4 or 6");
	draw_menu_plus(mlx, win, y);
}
