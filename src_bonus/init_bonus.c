/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:27:06 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/03 21:41:02 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THIS FUNCION INITIALIZE ONE WINDOW AND GET THE ADDRESS	*/
/*	FOR THE IMAGE BUFFER									*/
void	ft_mlx_init(t_fdf *fdf, char *file)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fatal_error("FDF: mlx_init() failed\n", fdf);
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, file);
	if (!fdf->mlx_win)
		fatal_error("FDF: mlx_new_window() failed\n", fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		fatal_error("FDF: mlx_new_image() failed\n", fdf);
	fdf->img_data = mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->line_len), &(fdf->endian));
	if (fdf->img_data == NULL)
		fatal_error("FDF: mlx_get_data_addr() failed\n", fdf);
}

/*	THIS FUNCION FINDS THE LIMIT MAX AND MIN VECTORS FROM THE MAP	*/
/*	IN ORDER TO CENTER AND SCALE THE IMAGE IN THE WINDOW			*/
static void	limits(t_fdf *fdf)
{
	int		x;
	int		y;

	fdf->borders.min.x = fdf->width;
	fdf->borders.min.y = fdf->height;
	fdf->borders.max.x = 0;
	fdf->borders.max.y = 0;
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->borders.min.x)
				fdf->borders.min.x = x;
			if (y < fdf->borders.min.y)
				fdf->borders.min.y = y;
			if (x > fdf->borders.max.x)
				fdf->borders.max.x = x;
			if (y > fdf->borders.max.y)
				fdf->borders.max.y = y;
			x++;
		}
		y++;
	}
}

/*	THIS FUNCTION CENTERS AND SCALES THE IMAGE			*/
/*	ALSO INITIALIZE THE ANGLES FOR THE ISOMETRIC VIEW	*/
void init_variables(t_fdf *fdf)
{
    float	width_range;  
    float 	max_range;
	float	height_range;
	
	limits(fdf);
	width_range = fdf->borders.max.x - fdf->borders.min.x;
    height_range = fdf->borders.max.y - fdf->borders.min.y;
	max_range = ft_max(width_range, height_range);
    fdf->zoom = ZOOM_FACTOR / max_range;
    fdf->move_x = WIDTH / 2 - ((fdf->borders.max.x + fdf->borders.min.x) / 2) * fdf->zoom;
    fdf->move_y = HEIGHT / 2 - ((fdf->borders.max.y + fdf->borders.min.y) / 2) * fdf->zoom;
	fdf->iso = 1;
	fdf->rotation = 0;
	fdf->left_view = 0;
	fdf->right_view = 0;
	fdf->ang_x = atan(sqrt(2));
	fdf->ang_z = 30;
	fdf->ang_y = 0;
	fdf->pad = 0.3;
}
