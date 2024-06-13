/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:32:30 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/13 12:59:01 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*draw(t_fdf *fdf)
{
	int		x;
	int		y;
	// t_3d	*p;
	// t_3d	*px;
	// t_3d	*py;

	mlx_clear_window(fdf->my_mlx, fdf->my_mlx_new_win);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				draw_line(x, y, x + 1, y, fdf);
			if (y < fdf->height - 1)
				draw_line(x, y, x, y + 1,fdf);
			x++;
		}
		y++;
	}
	return (NULL);
}
/*
void *draw(t_fdf *fdf) {
    int x, y;
    t_3d *p, *px, *py;

    mlx_clear_window(fdf->my_mlx, fdf->my_mlx_new_win);
    y = 0;
    while (y < fdf->height) {
        x = 0;
        while (x < fdf->width) {
            if (fdf->map[y][x] == NULL) {
                ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x);
                return NULL;
            }
            p = data_point(x, y, fdf->map[y][x]);
            if (p == NULL) {
                ft_printf("Error: data_point devolvió NULL para (%d, %d).\n", x, y);
                return NULL;
            }

            if ((x + 1) < fdf->width) {
                if (fdf->map[y][x + 1] == NULL) {
                    ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x + 1);
                    free(p);
                    return NULL;
                }
                px = data_point(x + 1, y, fdf->map[y][x + 1]);
                if (px == NULL) {
                    ft_printf("Error: data_point devolvió NULL para px (%d, %d).\n", x + 1, y);
                    free(p);
                    return NULL;
                }
                bresenham(p, px, fdf);
                free(px);
            }

            if ((y + 1) < fdf->height) {
                if (fdf->map[y + 1][x] == NULL) {
                    ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y + 1, x);
                    free(p);
                    return NULL;
                }
                py = data_point(x, y + 1, fdf->map[y + 1][x]);
                if (py == NULL) {
                    ft_printf("Error: data_point devolvió NULL para py (%d, %d).\n", x, y + 1);
                    free(p);
                    return NULL;
                }
                bresenham(p, py, fdf);
                free(py);
            }

            free(p);
            x++;
        }
        y++;
    }
    return NULL;
}
*/
/*
void *draw(t_fdf *fdf) {
    int x, y;
    t_3d *p, *px, *py;

    mlx_clear_window(fdf->my_mlx, fdf->my_mlx_new_win);
    y = 0;
    while (y < fdf->height) {
        x = 0;
        while (x < fdf->width) {
            if (fdf->map[y][x] == NULL) {
                ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x);
                return NULL;
            }
            p = data_point(x, y, fdf->map[y][x]);
            if (p == NULL) {
                ft_printf("Error: data_point devolvió NULL para (%d, %d).\n", x, y);
                return NULL;
            }

            if ((x + 1) < fdf->width) {
                if (fdf->map[y][x + 1] == NULL) {
                    ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x + 1);
                    //free(p);
                    return NULL;
                }
                px = data_point(x + 1, y, fdf->map[y][x + 1]);
                if (px == NULL) {
                    ft_printf("Error: data_point devolvió NULL para px (%d, %d).\n", x + 1, y);
                    //free(p);
                    return NULL;
                }
                bresenham(p, px, fdf);
                //free(px);
            }

            if ((y + 1) < fdf->height) {
                if (fdf->map[y + 1][x] == NULL) {
                    ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y + 1, x);
                    //free(p);
                    return NULL;
                }
                py = data_point(x, y + 1, fdf->map[y + 1][x]);
                if (py == NULL) {
                    ft_printf("Error: data_point devolvió NULL para py (%d, %d).\n", x, y + 1);
                   // free(p);
                    return NULL;
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
    return NULL;
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

void set_zoom(t_3d *p1, t_3d *p2, t_fdf *fdf)
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

int	draw_line(int x1, int y1, int x2, int y2, t_fdf *fdf)
{
	t_3d	pa;
	t_3d	pb;
	
	p1.x = x1;
	p1.y = y1;
	p1.z = ft_atoi(fdf->map[y1][x1]);
	p1.color = get_color(fdf->map[y1][x1], fdf);
	p2.x = x2;
	p2.y = y2;
	p2.z = ft_atoi(fdf->map[y2][x2]);
	p2.color = get_color(fdf->map[y2][x2], fdf);
	set_zoom(&pa, &pb, fdf);
	set_move(&pa, &pb, fdf);
	bresenham(&pa, &pb);
}
	// x0 = (x0 - z0) / RAC2;
	// y0 = (x0 + (y0 * 2) + z0) / RAC6;
	// x1 = (x1 - z1) / rac2;
	// y1 = (x1 + (y1 * 2) + z1) / rac6;	

void	calcul_bresenham(t_bres *var, t_3d *p1, t_3d *p2)
{
	var->dx = ft_abs(p1->x1 - p0->x0);
	var->dy = ft_abs(p0->y1 - p1->y0);
	if (var->dx > var->dy)
		var->d = var->dx;
	else
		var->d = var->dy;
	if (pa->x < pb->x)
		var->sx = 1;
	else
		var->sx = -1;
	if (pa->y < pb->y)
		var->sy = 
	var->error = var->dx - var->dy;
	var->ratio = 0.0;
	var->pixel = 0.0;
}

int	bresenham(t_3d *pa,t_3d *pb, t_fdf *fdf)
{
	t_bresenham	var;
	int		k;

	k = -1;
	calcul_bresenham(&var, pa, pb, fdf->map);
	while (++k <= var.d)
	{
		if (var.step == 0)
			var.ratio = 0.0f;
		else
			var.ratio = (float)i / var.step;
		var->color = color_grad((*pa).color, (*pb).color, var.d);
		mlx_pixel_put(df->my_mlx, fdf->my_mlx_new_win, pa->x, pa->y, grad(var.color));
		if ((pa->x == pb->x) && (pa->y == pb->y))
			break ;
		if ((2 * var.error) > -var->dy)
		{
			var.error -= var.dy;
			pa->x += var.sx;			
		}
		if (2 * var.error < var.dx)
		{
			var.error += var.dx
			pa->y +=var.sy;	
		}
	}
	return (0);
}

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
// 		mlx_pixel_put(fdf->my_mlx, fdf->my_mlx_new_win, xa, ya, color);
// 		xa += dx;
// 		ya += dy;
// 	}
// 	return (0);
// }
