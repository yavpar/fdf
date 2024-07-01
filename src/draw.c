/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:32:30 by yparthen          #+#    #+#             */
/*   Updated: 2024/07/01 09:18:25 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static void init_image(t_fdf *fdf);

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				get_points(x, y, x + 1, y, fdf);
			if (y < fdf->height - 1)
				get_points(x, y, x, y + 1, fdf);
			x++;
		}
		y++;
	}
	//render_image(fdf);
}

// static void init_image(t_fdf *fdf)
// {
//     fdf->img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
//     fdf->img_data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_len, &fdf->endian);
// }

/*	THIS FUNCTION PUTS THE IMAGE IN THE WINDOW	*/
// void render_image(t_fdf *fdf)
// {
//     init_image(fdf); // Inicializa una nueva imagen.
//     draw(fdf); // Dibuja todas las líneas en el buffer de la imagen.
//     mlx_put_image_to_window(fdf->mlx, fdf->mlx_new_win, fdf->img, 0, 0); // Muestra la imagen en la ventana.
//     mlx_destroy_image(fdf->mlx, fdf->img); // Destruye la imagen para liberar la memoria.
// }

void	render_image(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_new_win, fdf->img, 0, 0);
}

/*	TIS FUNCTION MODIFIES DIRECTLY THE BUFFER TO DRAW LINES	*/
void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x >= 0 && x < fdf->width && y >= 0 && y < fdf->height)
		fdf->img_data[(x * fdf->bpp / 8) + (y * fdf->line_len)] = color;
}
		//fdf->img_data[(y * (fdf->line_len / 4)) + x] = color;

void	set_zoom(t_3d *p1, t_3d *p2, t_fdf *fdf)
{
	p1->x *= fdf->zoom;
	p1->y *= fdf->zoom;
	p2->x *= fdf->zoom;
	p2->y *= fdf->zoom;
}

void	set_move(t_3d *p1, t_3d *p2, t_fdf *fdf)
{
	p1->x += fdf->move_x;
	p1->y += fdf->move_y;
	p2->x += fdf->move_x;
	p2->y += fdf->move_y;
}

void	get_points(int x1, int y1, int x2, int y2, t_fdf *fdf)
{
	t_3d	p1;
	t_3d	p2;

	p1.x = x1;
	p1.y = y1;
	p1.z = ft_atoi(fdf->map[y1][x1]);
	p1.color = get_color(fdf->map[y1][x1]);
	p1 = to_iso(p1, fdf);
	p2.x = x2;
	p2.y = y2;
	p2.z = ft_atoi(fdf->map[y2][x2]);
	p2 = to_iso(p2, fdf);
	p2.color = get_color(fdf->map[y2][x2]);
	set_zoom(&p1, &p2, fdf);
	set_move(&p1, &p2, fdf);
	draw_line(p1, p2, fdf);
}

void	draw_line(t_3d p1, t_3d p2, t_fdf *fdf)
{
	int	delta_x;
	int	delta_y;

	delta_x = ft_abs(p2.x - p1.x);
	delta_y = ft_abs(p2.y - p1.y);
	if (delta_x > delta_y)
	{
		if (p2.x - p1.x > 0)
			draw_pixel_low(p1, p2, fdf);
		else
			draw_pixel_low(p2, p1, fdf);
	}
	else
	{
		if (p2.y - p1.y > 0)
			draw_pixel_high(p1, p2, fdf);
		else
			draw_pixel_high(p2, p1, fdf);
	}
}

void	draw_pixel_low(t_3d p1, t_3d p2, t_fdf *fdf)
{
	t_bresenham	var;
	t_3d		p0;
	t_3d		temp;
	
	if (p1.x > p2.x)
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
	}

	var.dx = p2.x - p1.x;
	var.dy = p2.y - p1.y;
	var.y_incr = 1;
	if (var.dy < 0)
	{
		var.y_incr = -1;
		var.dy *= -1;
	}
	var.d = (2 * var.dy) - var.dx;
	p0.x = p1.x;
	p0.y = p1.y;
	while (p0.x <= p2.x)
	{
		mlx_pixel_put(fdf->mlx, fdf->mlx_new_win, p0.x, p0.y, p1.color);
		//put_pixel(fdf, p0.x, p0.y, p1.color);
		if (var.d > 0)
		{
			p0.y += var.y_incr;
			var.d += var.dx * (-2);
		}
		var.d += var.dy * 2;
		p0.x++;
	}
}

void	draw_pixel_high(t_3d p1, t_3d p2, t_fdf *fdf)
{
	t_bresenham	var;
	t_3d		p0;
	t_3d		temp;

	if (p1.y > p2.y)
	{
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	var.dx = p2.x - p1.x;
	var.dy = p2.y - p1.y;
	var.x_incr = 1;
	if (var.dx < 0)
	{
		var.x_incr = -1;
		var.dx *= -1;
	}
	var.d = (2 * var.dx) - var.dy;
	p0.x = p1.x;
	p0.y = p1.y;
	while (p0.y <= p2.y)
	{
		//put_pixel(fdf, p0.x, p0.y, p1.color);
		mlx_pixel_put(fdf->mlx, fdf->mlx_new_win, p0.x, p0.y, p1.color);
		if (var.d > 0)
		{
			p0.x += var.x_incr;
			var.d += var.dy * (-2);
		}
		var.d += var.dx * 2;
		p0.y++;
	}
}
// void	to_iso(t_3d *p)
// {
// 	p->x = (p->x - p->y) * cos(0.01);
// 	p->y = (p->x + p->y) * sin(0.01) - p->z;
// }

// void	calcul_bresenham(t_bresenham *var, t_3d *pa, t_3d *pb)
// {
// 	var->dx = ft_abs(pb->x - pa->x);
// 	var->dy = ft_abs(pb->y - pa->y);
// 	if (var->dx > var->dy)
// 		var->d = var->dx;
// 	else
// 		var->d = var->dy;
// 	var->dx /= var->d;
// 	var->dy /= var->d;
// }

// void	put_pixel(t_fdf *fdf, int x, int y, int color)
// {

// }

// int	bresenham(t_3d *pa, t_3d *pb, t_fdf *fdf)
// {
// 	t_bresenham	var;

// 	calcul_bresenham(&var, pa, pb);
// 	while ((int)(pa->x - pb->x) || (int)(pa->y - pb->y))
// 	{
// 		//var.pixel = color_grad((*pa).color, (*pb).color, var.d);
// 		mlx_pixel_put(fdf->mlx, fdf->mlx_new_win, pa->x, pa->y,
		//	pa->color);
// 		pa->x += var.dx;
// 		pa->y += var.dy;
// 	}
// 	return (0);
// }

/*For Bresenham*/

// if (pa->x < pb->x)
// 	var->sx = 1;
// else
// 	var->sx = -1;
// if (pa->y < pb->y)
// 	var->sy = var->error = var->dx - var->dy;
// var->ratio = 0.0;
// var->pixel = 0.0;

/*--------------------------------------------------------------*/
// if (var.step == 0)
// 	var.ratio = 0.0f;
// else
// 	var.ratio = (float)k / var.step;

// if ((pa->x == pb->x) && (pa->y == pb->y))
// 	break ;
// if ((2 * var.error) > -var.dy)
// {
// 	var.error -= var.dy;
// 	pa->x += var.sx;
// }
// if (2 * var.error < var.dx)
// {
// 	var.error += var.dx;
// 	pa->y += var.sy;
// }

/*
void	*draw(t_fdf *fdf) {
	int x, y;
	t_3d *p, *px, *py;

	mlx_clear_window(fdf->mlx, fdf->mlx_new_win);
	y = 0;
	while (y < fdf->height) {
		x = 0;
		while (x < fdf->width) {
			if (fdf->map[y][x] == NULL) {
				ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x);
				return (NULL);
			}
			p = data_point(x, y, fdf->map[y][x]);
			if (p == NULL) {
				ft_printf("Error: data_point devolvió NULL para (%d, %d).\n", x,
					y);
				return (NULL);
			}

			if ((x + 1) < fdf->width) {
				if (fdf->map[y][x + 1] == NULL) {
					ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x + 1);
					free(p);
					return (NULL);
				}
				px = data_point(x + 1, y, fdf->map[y][x + 1]);
				if (px == NULL) {
					ft_printf("Error: data_point devolvió NULL para px (%d,
						%d).\n", x + 1, y);
					free(p);
					return (NULL);
				}
				bresenham(p, px, fdf);
				free(px);
			}

			if ((y + 1) < fdf->height) {
				if (fdf->map[y + 1][x] == NULL) {
					ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y + 1, x);
					free(p);
					return (NULL);
				}
				py = data_point(x, y + 1, fdf->map[y + 1][x]);
				if (py == NULL) {
					ft_printf("Error: data_point devolvió NULL para py (%d,
						%d).\n", x, y + 1);
					free(p);
					return (NULL);
				}
				bresenham(p, py, fdf);
				free(py);
			}

			free(p);
			x++;
		}
		y++;
	}
	return (NULL);
}
*/
/*
void	*draw(t_fdf *fdf) {
	int x, y;
	t_3d *p, *px, *py;

	mlx_clear_window(fdf->mlx, fdf->mlx_new_win);
	y = 0;
	while (y < fdf->height) {
		x = 0;
		while (x < fdf->width) {
			if (fdf->map[y][x] == NULL) {
				ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x);
				return (NULL);
			}
			p = data_point(x, y, fdf->map[y][x]);
			if (p == NULL) {
				ft_printf("Error: data_point devolvió NULL para (%d, %d).\n", x,
					y);
				return (NULL);
			}

			if ((x + 1) < fdf->width) {
				if (fdf->map[y][x + 1] == NULL) {
					ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x + 1);
					//free(p);
					return (NULL);
				}
				px = data_point(x + 1, y, fdf->map[y][x + 1]);
				if (px == NULL) {
					ft_printf("Error: data_point devolvió NULL para px (%d,
						%d).\n", x + 1, y);
					//free(p);
					return (NULL);
				}
				bresenham(p, px, fdf);
				//free(px);
			}

			if ((y + 1) < fdf->height) {
				if (fdf->map[y + 1][x] == NULL) {
					ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y + 1, x);
					//free(p);
					return (NULL);
				}
				py = data_point(x, y + 1, fdf->map[y + 1][x]);
				if (py == NULL) {
					ft_printf("Error: data_point devolvió NULL para py (%d,
						%d).\n", x, y + 1);
					// free(p);
					return (NULL);
				}
				bresenham(p, py, fdf);
				//free(py);
			}

			//free(p);
			x++;
ft_printf("valores de punteros de t_3d:\np=%p px=%p py=%p", p, px, py);
		}
		y++;
	}
	return (NULL);
}
*/
// void	projection_2d(t_3d *p)
// {
// 	float	rac2;
// 	float	rac6;

// 	rac2 = 1.414213562;
// 	rac6 = 2.449489743;
// 	p->x = (p->x - p->z) / rac2;
// 	p->y = (p->x + (p->y * 2) + p->z) / rac6;
// }

// int	bresenham(int xa, int ya, int xb, int yb, t_fdf *fdf)
// {
// 	float	dx;
// 	float	dy;
// 	float	d;

// 	set_zoom()
// //za = ft_atoi(fdf->map[ya][xa]);
// // zb = ft_atoi(fdf->map[yb][xb]);
// 	// if (za > 0)
// 	// 	color = 0xFFFF00;
// 	// else if (za < 0)
// 	// 	color = 0xe80c0c;
// 	// else
// 	// 	color = 0xff00ff;
// 	xa *= fdf->zoom;
// 	xb *= fdf->zoom;
// 	ya *= fdf->zoom;
// 	yb *= fdf->zoom;
// 	dx = xb - xa;
// 	dy = yb - ya;
// 	// xa = (xa - ya) * COS_ANG;
// 	// ya = ((xa + ya) * SIN_ANG) - za;
// 	// xb = (xb - yb) * COS_ANG;
// 	// yb = ((xb + yb) * SIN_ANG) - zb;
// 	xa += fdf->shift_x;
// 	xb += fdf->shift_x;
// 	ya += fdf->shift_y;
// 	yb += fdf->shift_y;
// 	d = ft_max(ft_abs(dx), ft_abs(dy));
// 	dx = (float)((dx) / d);
// 	dy = (float)((dy) / d);
// 	while ((int)(xa - xb) || (int)(ya - yb))
// 	{
// 		mlx_pixel_put(fdf->mlx, fdf->mlx_new_win, xa, ya, color);
// 		xa += dx;
// 		ya += dy;
// 	}
// 	return (0);
// }

// x0 = (x0 - z0) / RAC2;
// y0 = (x0 + (y0 * 2) + z0) / RAC6;
// x1 = (x1 - z1) / RAC2;
// y1 = (x1 + (y1 * 2) + z1) / rac6;
