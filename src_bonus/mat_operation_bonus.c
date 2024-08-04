/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_operation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:04 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/02 13:34:04 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdio.h>
#include <math.h>

/*	THIS FUNCION RETURNS THE ROTATION MATRIX ON THE X AXIS	*/
static t_matrix	rot_matrix_x(float alpha)
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

/*	THIS FUNCION RETURNS THE ROTATION MATRIX ON THE Y AXIS	*/
static t_matrix	rot_matrix_y(float alpha)
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

/*	THIS FUNCION RETURNS THE ROTATION MATRIX ON THE Z AXIS	*/
static t_matrix	rot_matrix_z(float alpha)
{
	float	c;
	float	s;
	float	ang;

	ang = alpha * PI / 180;
	c = cos(ang);
	s = sin(ang);
	return ((t_matrix){
		(t_3d){c, -s, 0, 0},
		(t_3d){s, c, 0, 0},
		(t_3d){0, 0, 1, 0}});
}

/*	THIS FUNCTION MULTIPLIES A MATRIX BY A VECTOR	*/
static t_3d	mat_x_vec(t_matrix m, t_3d v)
{
	float	*f;

	f = (float [3]){v.x, v.y, v.z};
	v.x = f[0] * m.i.x + f[1] * m.i.y + f[2] * m.i.z;
	v.y = f[0] * m.j.x + f[1] * m.j.y + f[2] * m.j.z;
	v.z = f[0] * m.k.x + f[1] * m.k.y + f[2] * m.k.z;
	return (v);
}

/*	THIS FUNCTION ROTATES THE IMAGE IN ORDER TO SET THE ISOMETRIC VIEW 	*/
/*	OR ANOTHER VIEW, LIKE FLAT VIEW										*/
t_3d	to_iso(t_3d v, t_fdf *fdf)
{
	if (fdf->rotation)
	{
		v = mat_x_vec(rot_matrix_z(fdf->ang_z), v);
		v = mat_x_vec(rot_matrix_x(fdf->ang_x), v);
		v = mat_x_vec(rot_matrix_y(fdf->ang_y), v);
	}
	else if (fdf->iso)
	{
		fdf->ang_x = atan(sqrt(2));
		fdf->ang_z = 30;
		v = mat_x_vec(rot_matrix_z(fdf->ang_z), v);
	 	v = mat_x_vec(rot_matrix_x(fdf->ang_x), v);
	}
	else if (fdf->right_view)
		v = mat_x_vec(rot_matrix_y(fdf->ang_z), v);
	else if (fdf->left_view)
		v = mat_x_vec(rot_matrix_y(fdf->ang_x), v);
	else
		v = v;
	return (v);
}
