/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:59:55 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/02 11:29:30 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	THIS FUNCTION CLOSE THE PROGAM WHEN ESC BUTTOM IS PRESSED	*/
int	esc_close(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		ft_clear(fdf, 1, 0);
	return (0);
}

/*	THIS FUNCTION CLOSE THE PROGAM WHEN X BUTTOM WINDOW IS CLICKED	*/
int	button_x_close(t_fdf *fdf)
{
	ft_clear(fdf, 1, 0);
	return (0);
}

/*	THIS FUNCION SHOWS INFORMATATION ABOUT THE PROGRAM NAME AND	*/
/*	THE TYPE OF VIEW OF THE IMAGE								*/
void	draw_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->mlx_win;
	mlx_string_put(mlx, win, 150, y += 20, WHITE, "********************");
	mlx_string_put(mlx, win, 150, y += 20, WHITE, "* Fil de Fer (FDF) *");
	mlx_string_put(mlx, win, 150, y += 20, WHITE, "********************");
	mlx_string_put(mlx, win, 15, y += 20, TEXT_COLOR, "ISOMETRIC VIEW");
}
