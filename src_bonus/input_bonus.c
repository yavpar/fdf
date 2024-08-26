/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:58:23 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/03 21:39:51 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THE FIRST 3 FONCTIONS MODIFYS THE PARAMETERS NECESSARY TO DRAW 	*/
/*	THE NEW LINES													*/
static void	input3(int keysym, t_fdf *fdf)
{
	if (keysym == 120)
	{
		fdf->ang_x = -PI / 2;
		fdf->rotation = 0;
		fdf->iso = 0;
		fdf->right_view = 0;
		fdf->left_view = 1;
	}
	else if (keysym == 121)
	{
		fdf->ang_z = PI / 2;
		fdf->rotation = 0;
		fdf->iso = 0;
		fdf->left_view = 0;
		fdf->right_view = 1;
	}
	else if (keysym == XK_f)
	{
		fdf->rotation = 0;
		fdf->iso = 0;
		fdf->left_view = 0;
		fdf->right_view = 0;
	}
}

static void	input2(int keysym, t_fdf *fdf)
{
	fdf->rotation = 1;
	fdf->iso = 0;
	fdf->left_view = 0;
	fdf->right_view = 0;
	if (keysym == 65436)
		fdf->ang_x -= 0.1;
	else if (keysym == 65434)
		fdf->ang_x += 0.1;
	else if (keysym == 65435)
		fdf->ang_y -= 0.1;
	else if (keysym == 65429)
		fdf->ang_y += 0.1;
	else if (keysym == 65430)
		fdf->ang_z += 1.0;
	else if (keysym == 65432)
		fdf->ang_z -= 1.0;
	else if (keysym == XK_i)
	{
		fdf->rotation = 0;
		fdf->iso = 1;	
	}
	else
		input3(keysym, fdf);
}

int	input(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		ft_clear(fdf, 1, 0);
	else if (keysym == XK_w || keysym == XK_Up || keysym == 122)
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

/*	THIS FUNCTION CLOSE THE PROGAM WHEN X BUTTOM WINDOW IS CLICKED	*/
int	button_x_close(t_fdf *fdf)
{
	ft_clear(fdf, 1, 0);
	return (0);
}

/*	THIS FUNCION SHOWS INFORMATATION ABOUT THE PROGRAM NAME AND				*/
/*	ALL THE FUNCTIONALITIES AVAIBLES IN ORDER TO INTERACT WITH THE IMAGE	*/
void	draw_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->mlx_win;
	mlx_string_put(mlx, win, 40, y += 20, WHITE, "Press the following keys:");
	mlx_string_put(mlx, win, 15, y += 50, TEXT, "Zoom:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, " + / - key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Pad +/-:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "8 / 2 key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Move:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Up arrow or w key");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Down arrow or s key");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Left arrow or a key");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Right arrow or d key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Z-Axis - Key 4 or 6");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Y-Axis - Key 7 or 3");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "Z-Axis - Key 4 or 6");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Top view:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "  f key");
	mlx_string_put(mlx, win, 15, y += 40, TEXT, "Isometric view:");
	mlx_string_put(mlx, win, 57, y += 25, WHITE, "i key");
}
