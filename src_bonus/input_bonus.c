/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:58:23 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/09 17:28:33 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THE FIRST 3 FONCTIONS MODIFYS THE PARAMETERS NECESSARY TO DRAW 	*/
/*	THE NEW LINES													*/

static void	input4(int keysym, t_fdf *fdf)
{
	if (keysym == XK_l)
	{
		fdf->paralelle_y = 1;
		fdf->ang_y = -PI / 2;
		fdf->ang_z = PI / 2;
		fdf->ang_x = 0;
		fdf->paralelle_x = 0;
		fdf->rotation = 0;
		fdf->iso = 0;
	}
	else if (keysym == XK_t)
	{
		fdf->rotation = 0;
		fdf->iso = 0;
		fdf->paralelle_x = 0;
		fdf->paralelle_y = 0;
	}
}

static void	input3(int keysym, t_fdf *fdf)
{
	if (keysym == 65436)
	{
		fdf->ang_x -= 0.1;
		fdf->rotation = 1;
	}
	else if (keysym == 65435)
	{
		fdf->rotation = 1;
		fdf->ang_y -= 0.1;
	}
	else if (keysym == 65429)
	{
		fdf->rotation = 1;
		fdf->ang_y += 0.1;
	}
	if (keysym == XK_f)
	{
		fdf->paralelle_x = 1;
		fdf->ang_x = PI / 2;
		fdf->ang_z = PI / 2;
		fdf->rotation = 0;
		fdf->iso = 0;
	}
	else
		input4(keysym, fdf);
}

static void	input2(int keysym, t_fdf *fdf)
{
	if (keysym == XK_i)
	{
		fdf->iso = 1;
		fdf->ang_x = atan(sqrt(2));
		fdf->ang_z = 30;
		fdf->rotation = 0;
	}
	else if (keysym == 65430)
	{
		fdf->rotation = 1;
		fdf->ang_z += 1.0;
	}
	else if (keysym == 65432)
	{
		fdf->rotation = 1;
		fdf->ang_z -= 1.0;
	}
	else if (keysym == 65434)
	{
		fdf->rotation = 1;
		fdf->ang_x += 0.1;
	}
	else
		input3(keysym, fdf);
}

int	input(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		ft_clear(fdf, 1, 0);
	else if (keysym == XK_w || keysym == XK_Up)
		fdf->move_y -= 5;
	else if (keysym == XK_s || keysym == XK_Down || keysym == 115)
		fdf->move_y += 5;
	else if (keysym == XK_d || keysym == XK_Right || keysym == 100)
		fdf->move_x += 5;
	else if (keysym == XK_a || keysym == XK_Left || keysym == 113)
		fdf->move_x -= 5;
	else if (keysym == 65451)
		fdf->zoom += 1;
	else if (keysym == 65453 || keysym == 45)
		fdf->zoom -= 1;
	else if (keysym == 65431)
		fdf->pad += 0.01;
	else if (keysym == 65433)
		fdf->pad -= 0.01;
	else
		input2(keysym, fdf);
	mlx_clear_window(fdf->mlx, fdf->mlx_win);
	draw(fdf);
	return (0);
}
