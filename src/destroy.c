/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:56 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/30 21:48:10 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear(t_fdf *fdf, int is_exit)
{
	if (fdf)
	{	
		if (fdf->mlx)
		{
			if (fdf->img)
			{
				mlx_destroy_window(fdf->mlx, fdf->mlx_new_win);
				mlx_destroy_display(fdf->mlx);
			}
			else if (fdf->mlx_new_win)
				mlx_destroy_display(fdf->mlx);
			free(fdf->mlx);
		}
		if (fdf->map)
			destroy_map(fdf);
		free(fdf);
	}
	if (is_exit)
		exit (1);
}

/*	This funcion cleans the map "char map[y][x][z]"		*/
void	destroy_map(t_fdf *fdf)
{
	int	x;
	int	y;

	if (fdf->map)
	{
		y = 0;
		while (y < fdf->height)
		{
			if (fdf->map[y])
			{
				x = 0;
				while (x < fdf->width)
				{
					if (fdf->map[y][x])
						free(fdf->map[y][x]);
					x++;
				}
				free(fdf->map[y]);
			}
			y++;
		}
		free(fdf->map);
	}
}
// void destroy_map(t_fdf *fdf) {
//     int y, x;

//     if (fdf->map) {
//         for (y = 0; y < fdf->height; y++) {
//             if (fdf->map[y]) {
//                 for (x = 0; x < fdf->width; x++) {
//                     if (fdf->map[y][x]) {
//                         free(fdf->map[y][x]);
//                     }
//                 }
//                 free(fdf->map[y]);
//             }
//         }
//         free(fdf->map);
//     }
// }