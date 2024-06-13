/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:56 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/10 20:00:09 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	This funcion cleans the map "char map[y][x][z]"		*/
/*	and the structure t_fdf								*/
// void	destroy_map(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	if (fdf)
// 	{
// 		if (fdf->map)
// 		{
// 			while (++y < fdf->height)
// 			{
// 				x = -1;
// 				while (++x < fdf->width)
// 				{
// 					if (fdf->map[y][x])
// 						free(fdf->map[y][x]);
// 				}
// 				free(fdf->map[y]);
// 			}
// 			free(fdf->map);
// 		}
// 		free(fdf);
// 	}
// }

void destroy_map(t_fdf *fdf) {
    int y, x;

    if (fdf->map) {
        for (y = 0; y < fdf->height; y++) {
            if (fdf->map[y]) {
                for (x = 0; x < fdf->width; x++) {
                    if (fdf->map[y][x]) {
                        free(fdf->map[y][x]);
                    }
                }
                free(fdf->map[y]);
            }
        }
        free(fdf->map);
    }
}