/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:04 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/29 18:42:20 by yparthen         ###   ########.fr       */
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
	// t_matrix	*m_x;
	// t_matrix	*m;

	// m_x = malloc(sizeof(t_matrix));
	// m_x->i.x = 1;
	// m_x->i.y = 0;
	// m_x->i.z = 0;
	// m_x->i.color = 0;
	// m_x->j.x = 0;
	// m_x->j.y = c;
	// m_x->j.z = -s;
	// m_x->j.color = 0;
	// m_x->k.x = 0;
	// m_x->k.y = s;
	// m_x->k.z = c;
	// m_x->k.color = 0;
	// m = m_x;
	// free(m_x);
	// return (m);
}
// static t_matrix	*rot_matrix_y(float alpha)
// {
// 	float		c;
// 	float		s;
// 	t_matrix	*m_y;
// 	t_matrix	*m;

// 	m_y = malloc(sizeof(t_matrix));
// 	c = cos(alpha);
// 	s = sin(alpha);
// 	m_y->i.x = c;
// 	m_y->i.y = 0;
// 	m_y->i.z = s;
// 	m_y->i.color = 0;
// 	m_y->j.x = 0;
// 	m_y->j.y = 1;
// 	m_y->j.z = 0;
// 	m_y->j.color = 0;
// 	m_y->k.x = -s;
// 	m_y->k.y = 0;
// 	m_y->k.z = c;
// 	m_y->k.color = 0;
// 	m = m_y;
// 	free(m_y);
// 	return (m);
// }

t_matrix	rot_matrix_z(float alpha)
{
	float	c;
	float	s;
	// t_matrix	*m_z;
	// t_matrix	*m;

	// m_z = malloc(sizeof(t_matrix));
	c = cos(grad_to_rad(alpha));
	s = sin(grad_to_rad(alpha));
		return ((t_matrix){
	(t_3d){c, 0, -s, 0},
	(t_3d){0, 1, 0, 0},
	(t_3d){s, 0, c, 0}});
	// m_z->i.x = c;
	// m_z->i.y = -s;
	// m_z->i.z = 0;
	// m_z->i.color = 0;
	// m_z->j.x = s;
	// m_z->j.y = c;
	// m_z->j.z = 0;
	// m_z->j.color = 0;
	// m_z->k.x = 0;
	// m_z->k.y = 0;
	// m_z->k.z = 1;
	// m_z->k.color = 0;
	// m = m_z;
	// free(m_z);
	// return (m);
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

t_3d	to_iso(t_3d v)
{
	double	ang_x;
	double	ang_z;
	t_3d	vect;

	ang_x = atan(sqrt(2));
	ang_z = 45;
	vect = mat_x_vec(rot_matrix_z(ang_z), v);
	vect = mat_x_vec(rot_matrix_x(ang_x), vect);
	// fdf->ang_x = ang_x;
	// fdf->ang_z = ang_z;
	// fdf->ang_y = 0;
	return (vect);
}
