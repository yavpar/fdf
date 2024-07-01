/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:04 by yparthen          #+#    #+#             */
/*   Updated: 2024/07/01 13:00:09 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

float	grad_to_rad(float deg)
{
	return (deg * PI / 180);
}

t_matrix	rot_matrix_x(float alpha)
{
	float		c;
	float		s;

	c = cos(alpha);
	s = sin(alpha);
	return ((t_matrix){
	(t_3d){1, 0, 0, 0},
	(t_3d){0, c, -s, 0},
	(t_3d){0, s, c, 0}});
}
t_matrix	rot_matrix_y(float alpha)
{
	float	c;
	float	s;
	c = cos(alpha);
	s = sin(alpha);
	return ((t_matrix){
		(t_3d){c, 0, -s, 0},
		(t_3d){0, 1, 0, 0},
		(t_3d){s, 0, c, 0}});
}

t_matrix	rot_matrix_z(float alpha)
{
	float	c;
	float	s;

	c = cos(grad_to_rad(alpha));
	s = sin(grad_to_rad(alpha));
	return ((t_matrix){
		(t_3d){c, -s, 0, 0},
		(t_3d){s, c, 0, 0},
		(t_3d){0, 0, 1, 0}});
}

// static t_matrix matriz_id(void)
// {
// 	return((t_matrix){
// 		(t_3d){1, 0, 0, 0},
// 		(t_3d){0, 1, 0, 0},
// 		(t_3d){0, 0, 1, 0}
// 	});
// }

t_3d	mat_x_vec(t_matrix m, t_3d v)
{
	float	*f;

	f = (float [3]){v.x, v.y, v.z};
	v.x = f[0] * m.i.x + f[1] * m.i.y + f[2] * m.i.z;
	v.y = f[0] * m.j.x + f[1] * m.j.y + f[2] * m.j.z;
	v.z = f[0] * m.k.x + f[1] * m.k.y + f[2] * m.k.z;
	return (v);
}

t_3d	to_iso(t_3d v, t_fdf *fdf)
{
	if (fdf->rot_z || fdf->rot_up_down)
	{
		if (fdf->rot_z)
			v = mat_x_vec(rot_matrix_z(fdf->ang_z), v);
		if (fdf->rot_up_down)
		{
			v = mat_x_vec(rot_matrix_x(fdf->ang_x), v);
			v = mat_x_vec(rot_matrix_y(fdf->ang_y), v);
		}
	}
	else
	{
		v = mat_x_vec(rot_matrix_z(fdf->ang_z), v);
		v = mat_x_vec(rot_matrix_x(fdf->ang_x), v);
	}
	return (v);
}

t_3d	rot_map(t_3d v, t_fdf *fdf)
{
	v = mat_x_vec(rot_matrix_z(fdf->ang_z), v);
	v = mat_x_vec(rot_matrix_x(fdf->ang_x), v);
	v = mat_x_vec(rot_matrix_y(fdf->ang_y), v);
	return (v);
}