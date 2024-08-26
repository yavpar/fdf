/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:39 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/03 21:42:23 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* ************************************************************************ */
/*	THIS PROGRAM FDF "FIL DE FER" READS A FILE AND DRAW LINES.				*/
/*	FIRST IT PARSES THE FILE AND CREATES A CHAR *** (3D ARRAY) IN WITCH		*/
/*	IT CONTAINS THE DATA OF SUCH FILE: COORDINATES X, Y, Z AND EVENTUALLY	*/
/*	A COLOR IN OPTION. 														*/
/*	FOR EACH ITERATION OF THE 3D ARRAY IT CALCULATES 4 VECTOR POINTS 		*/
/*	AND DRAW 2 WHITE LINES:													*/
/*	LINE 1: P1(X, Y) P2(X + 1, Y) (HORIZONTAL)								*/
/*	LINE 2: P2(X, Y) P4(X, Y + 1) (VERTIACL)								*/
/*	THE IMAGE SHOWN IS IN ISOMETRIC PROJECTION								*/
/*	ITS USES MLX LIBRARY IN ORDER TO CREAT A WINDOW TO DRAW THE LINES		*/
/* ************************************************************************ */
int	main(int ac, char **av) 
{
	t_fdf	*fdf;

	if (ac != 2)
	{
		ft_putstr_fd("FDF: Incorrect number of arguments\n", 2);
		ft_putstr_fd("Expected: ./fdf <filemane.fdf>\n", 2);
		return (1);
	}
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (fdf == NULL)
	{
		ft_putstr_fd("FDF: Error malloc for main struct\n", 2);
		return (1);
	}
	fdf->bonus = 0;
	parse_file(av[1], fdf);
	init_variables(fdf);
	ft_mlx_init(fdf, av[1]);
	draw(fdf);
	mlx_key_hook(fdf->mlx_win, &esc_close, fdf);
	mlx_hook(fdf->mlx_win, 17, 0, &button_x_close, fdf);
	mlx_loop(fdf->mlx);
	ft_clear(fdf, 1, 0);
	return (0);
}
