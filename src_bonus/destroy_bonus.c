/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:56 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/02 10:43:32 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THIS FUNCTION DESTROY THE WINDOW AND FREES THE 3D ARRAY		*/
void	ft_clear(t_fdf *fdf, int is_exit, int exit_code)
{
	if (fdf)
	{
		if (fdf->mlx)
		{
			if (fdf->img)
			{
				mlx_destroy_image(fdf->mlx, fdf->img);
			}
			if (fdf->mlx_win)
			{
				mlx_destroy_window(fdf->mlx, fdf->mlx_win);
			}
			if (fdf->mlx)
				mlx_destroy_display(fdf->mlx);
			free(fdf->mlx);
		}
		if (fdf->map)
			destroy_map(fdf);
		free(fdf);
	}
	if (is_exit)
		exit (exit_code);
}

/*	This funcion cleans the map "char map[y][x][z]"		*/
void	destroy_map(t_fdf *fdf)
{
	int	x;
	int	y;

	if (fdf->map)
	{
		y = 0;
		while (y < fdf->height || fdf->map[y] != NULL)
		{
			if (fdf->map[y] != NULL)
			{
				x = 0;
				while (x < fdf->width || fdf->map[y][x] != NULL)
				{
					if (fdf->map[y][x] != NULL)
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

void	fatal_error(char *str, t_fdf *fdf)
{
	ft_putstr_fd(str, 2);
	if (fdf)
	{
		if (fdf->mlx)
			ft_clear(fdf, 1, 1);
		else if (fdf->map)
		{
			destroy_map(fdf);
			exit (1);
		}
		else
		{
			free(fdf);
			exit (1);
		}
	}
	else
		exit (1);
}
