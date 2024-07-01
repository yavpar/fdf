/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:17:38 by yparthen          #+#    #+#             */
/*   Updated: 2024/07/01 09:35:59 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	to_iso(t_3d *p)
// {
// 		(p->x - p->z) / sqrt(2);
// 		(p->x + (p->y * 2) + p->z) / sqrt(6);
// }

t_3d	to_iso(t_3d v, t_fdf *fdf)
{
	double	ang_x;
	double	ang_z;

	if (fdf->rot_z)
		return (mat_x_vec(rot_matrix_z(fdf->ang_z), v));
	else if (fdf->rot_up_down)
	{
		v = mat_x_vec(rot_matrix_x(fdf->ang_x), v);
		v = mat_x_vec(rot_matrix_y(fdf->ang_y), v);
		return (v);
	}
	else
	{
		ang_x = atan(sqrt(2));
		ang_z = 30;
		v = mat_x_vec(rot_matrix_z(ang_z), v);
		v = mat_x_vec(rot_matrix_x(ang_x), v);
		fdf->ang_x = ang_x;
		fdf->ang_z = ang_z;
		fdf->ang_x = 0;
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
