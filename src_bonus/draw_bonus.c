/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:32:30 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/02 14:27:27 by yparthen         ###   ########.fr       */
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

/*	THIS FUNCTION CALCULATES THE PARAMETERS IN ORDER TO DRAWING	*/
/*	A LINE BETWEEN TWO POINTS WITH DDA ALGORITHM			*/
void draw_pixels(t_3d p1, t_3d p2, t_fdf *fdf)
{
	t_bresenham	var;
	t_3d	p0;
	float	factor;
	
	var.dx = p2.x - p1.x;
	var.dy = p2.y - p1.y;
	var.steps = ft_max(ft_abs(var.dx), ft_abs(var.dy));
	var.x_incr = var.dx / var.steps;
	var.y_incr = var.dy / var.steps;
	var.i = 0;
	p0.x = p1.x;
	p0.y = p1.y;
	while (var.i <= var.steps)
	{
		factor = (float)var.i / var.steps;
		var.pixel = interpolate_color(p1.color, p2.color, factor);
		pixel_put_to_image(fdf, round(p0.x), round(p0.y), var.pixel);
		p0.x += var.x_incr;
		p0.y += var.y_incr;
		var.i++;
	}
}

/*	THIS FUNCTION INITIALIZES TWO VECTORS POINT AND DRAW ONE LINE	*/
/*	BETWEEN THE TWO POINTS											*/
void	draw_lines(int x1, int y1, int x2, int y2, t_fdf *fdf)
{
	t_3d	p1;
	t_3d	p2;
	
	p1.x = x1;
	p1.y = y1;
	p1.z = ft_atoi(fdf->map[y1][x1]) * fdf->pad;
	p1.color = get_color(fdf->map[y1][x1], fdf);
	p2.x = x2;
	p2.y = y2;
	p2.z = ft_atoi(fdf->map[y2][x2]) * fdf->pad;
	p2.color = get_color(fdf->map[y2][x2], fdf);
	p1 = to_iso(p1, fdf);
	p2 = to_iso(p2, fdf);
	p1.x *= fdf->zoom;
	p1.y *= fdf->zoom;
	p2.x *= fdf->zoom;
	p2.y *= fdf->zoom;
	p1.x += fdf->move_x;
	p1.y += fdf->move_y;
	p2.x += fdf->move_x;
	p2.y += fdf->move_y;
	draw_pixels(p1, p2, fdf);
}

/*	THIS FUNCTION ITERATES THE ARRAY AND DRAWS THE MAP	*/
int	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				draw_lines(x, y, x + 1, y, fdf);
			if (y < fdf->height - 1)
				draw_lines(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
	draw_menu(fdf);
	return (0);
}
