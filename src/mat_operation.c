/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:24:04 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/12 11:41:40 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*rot_matrix_x(float alpha)
{
	float		c;
	float		s;
	t_matrix	*m_x;
	t_matrix	*m;
	
	m_x = malloc(sizeof(t_matrix));
	c = cos(alpha);
	s = sin(alpha);
	m_x->i.x = 1;
	m_x->i.y = 0;
	m_x->i.z = 0;
	m_x->i.color = 0;
	m_x->j.x = 0;
	m_x->j.y = c;
	m_x->j.z = -s;
	m_x->j.color = 0;
	m_x->k.x = 0;
	m_x->k.y = s;
	m_x->k.z = c;
	m_x->k.color = 0;
	m = m_x;
	free(m_x);
	return (m);
}
t_matrix	*rot_matrix_y(float alpha)
{
	float		c;
	float		s;
	t_matrix	*m_y;
	t_matrix	*m;

	m_y = malloc(sizeof(t_matrix));
	c = cos(alpha);
	s = sin(alpha);
	m_y->i.x = c;
	m_y->i.y = 0;
	m_y->i.z = s;
	m_y->i.color = 0;
	m_y->j.x = 0;
	m_y->j.y = 1;
	m_y->j.z = 0;
	m_y->j.color = 0;
	m_y->k.x = -s;
	m_y->k.y = 0;
	m_y->k.z = c;
	m_y->k.color = 0;
	m = m_y;
	free(m_y);
	return (m);
}

t_matrix	*rot_matrix_z(float alpha)
{
	float	c;
	float	s;
	t_matrix	*m_z;
	t_matrix	*m;

	m_z = malloc(sizeof(t_matrix));
	c = cos(alpha);
	s = sin(alpha);
ft_printf("cos(a)=%f\tsin(a)=%f\n", c, s);
	m_z->i.x = c;
	m_z->i.y = -s;
	m_z->i.z = 0;
	m_z->i.color = 0;
	m_z->j.x = s;
	m_z->j.y = c;
	m_z->j.z = 0;
	m_z->j.color = 0;
	m_z->k.x = 0;
	m_z->k.y = 0;
	m_z->k.z = 1;
	m_z->k.color = 0;
	m = m_z;
	free(m_z);
	return (m);
}

t_matrix	matriz_id(void)
{
	return((t_matrix){
		(t_3d){1, 0, 0, 0},
		(t_3d){0, 1, 0, 0},
		(t_3d){0, 0, 1, 0}
	});
}

t_3d	*mat_x_vec(t_matrix *m, t_3d *v)
{
	v->x = m->i.x * vt->x + m->j.y * vt->y + m->k.z * vt->z;
	v->y = m->i.y * vt->x + m->j.y * vt->y + m->k.z * vt->z;
	v->z = m->i.z * vt->x + m->j.y * vt->y + m->k.z * vt->z;
	v->color = 0;
	return (v);
}

t_3d	*to_iso(t_3d *v, t_fdf *fdf)
{
	double	ang_x;
	double	ang_z;
	t_3d	*vect;

	vect = v;
	ang_z = 45;
	ang_x = atan(sqrt(2));
	vect = mat_x_vec(rot_matrix_z(ang_z), v);
	vect = mat_x_vec(rot_matrix_x(ang_x), vect);
	fdf->ang_x = ang_x;
	fdf->ang_z = ang_z;
	fdf->ang_y = 0;
	return (vect);
}
