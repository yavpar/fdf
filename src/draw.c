/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:32:30 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/08 18:06:17 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	THIS FUNCTION CALCULATE THE POSITIONS TO PUT A PIXEL IN THE LINE	*/
void	draw_pixels(t_3d p1, t_3d p2, t_fdf *fdf)
{
	t_line	var;
	t_3d	p0;

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
		pixel_put_to_image(fdf, round(p0.x), round(p0.y), p1.color);
		p0.x += var.x_incr;
		p0.y += var.y_incr;
		var.i++;
	}
}

/*	THIS FUNCION GENERATES A VECTOR POINT AND APLY AN ISOMETRIC VIEW	*/
t_3d	get_point(int x, int y, t_fdf *fdf)
{
	t_3d	p;

	p.x = x;
	p.y = y;
	p.z = ft_atoi(fdf->map[y][x]) * fdf->pad;
	p.color = get_color(fdf->map[y][x], fdf);
	return (to_iso(p, fdf));
}

/*	THIS FUNCTION APLIES A ZOOM FACTOR AND MOVES THE IMAGE	*/
/*	THEN IT DRAW A LINE BETWEENT TWO POINTS					*/
void	draw_lines(t_3d p1, t_3d p2, t_fdf *fdf)
{
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
	while (fdf->map[y] != NULL)
	{
		x = 0;
		while (fdf->map[y][x] != NULL)
		{
			if (fdf->map[y][x + 1] != NULL)
				draw_lines(get_point(x, y, fdf), get_point(x + 1, y, fdf), fdf);
			if ((y < fdf->height - 1) && (fdf->map[y + 1][x] != NULL))
				draw_lines(get_point(x, y, fdf), get_point(x, y + 1, fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
	draw_menu(fdf);
	return (0);
}
