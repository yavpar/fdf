/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:39 by yparthen          #+#    #+#             */
/*   Updated: 2024/07/01 13:01:15 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	tecla - valor
	y = 121
	x = 120
	z = 119*/
static int	handle_input(int keysym, t_fdf *fdf);
static void	handle_input2(int keysym, t_fdf *fdf);

static int	handle_input(int keysym, t_fdf *fdf)
{
	ft_printf("%d\n", keysym);
	if (keysym == 122)
		fdf->move_y -= 50; // up
	if (keysym == 115)
		fdf->move_y += 50; // down;
	if (keysym == 100)
		fdf->move_x += 50; // right;
	if (keysym == 113)
		fdf->move_x -= 50; // left;
	if (keysym == 65451)
		fdf->zoom += 10;
	if (keysym == 65453)
		fdf->zoom -= 10;
	if (keysym == XK_Escape)
		ft_clear(fdf, 1);
	else
		handle_input2(keysym, fdf);
	mlx_clear_window(fdf->mlx, fdf->mlx_new_win);
	draw(fdf);
	return (0);
}

static void	handle_input2(int keysym, t_fdf *fdf)
{
	fdf->rot_z = 0;
	fdf->rot_up_down = 0;
	fdf->iso = 0;
	if (keysym == 65362) //up
	{
		fdf->ang_x += 0.1;
		fdf->ang_y += 0.1;
		fdf->rot_up_down = 1;
	}
	if (keysym == 65364) // down
	{
		fdf->ang_x -= 0.1;
		fdf->ang_y -= 0.1;
		fdf->rot_up_down = 1;
	}
	if (keysym == 65363) //right
	{
		fdf->ang_z += 0.1;
		fdf->rot_z = 1;
	}
	if (keysym == 65361) // left
	{
		fdf->ang_z -= 0.1;
		fdf->rot_z = 1;
	}
}

int	close_window(t_fdf *fdf)
{
	ft_clear(fdf, 1);
	return (0);
}

void	ft_mlx_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_clear(fdf, 1);
	fdf->mlx_new_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT,
			"*** Fil De Fer ***");
	if (!fdf->mlx_new_win)
		ft_clear(fdf, 1);
	fdf->img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	if (!fdf->img)
		ft_clear(fdf, 1);
	fdf->img_data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_len,
			&fdf->endian);
}

void	center_n_scale(t_fdf *fdf)
{
	float	x;
	float	y;
	double	ang_x;
	double	ang_z;
	
	ang_x = atan(sqrt(2));
	ang_z = 30;
	x = (float)WIDTH * (1 - MARGIN) / (float)fdf->width;
 	y = (float)HEIGHT * (1 - MARGIN) / (float)fdf->height;
	fdf->zoom = ft_min(x, y);
	fdf->move_x = WIDTH / 2;
	fdf->move_y = HEIGHT / 2;
	fdf->rot_up_down = 0;
	fdf->rot_z = 0;
	fdf->iso = 1;
	fdf->ang_x = ang_x;
	fdf->ang_z = ang_z;
	fdf->ang_y = fdf->ang_x;
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		return (1);
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (fdf == NULL)
		return (1);
	parse_file(av[1], fdf);
	center_n_scale(fdf);
	ft_mlx_init(fdf);
	fdf->iso = 1;
	draw(fdf);
	mlx_key_hook(fdf->mlx_new_win, &handle_input, fdf);
	mlx_hook(fdf->mlx_new_win, 17, 0, &close_window, fdf);
	mlx_loop(fdf->mlx);
	ft_clear(fdf, 0);
	return (0);
}

void	print_map(char ***map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_printf(" %s ", map[y][x]);
			x++;
		}
		y++;
		ft_printf("\n");
	}
}

// mlx_loop_hook(fdf->mlx, &deal_key, fdf);
// mlx_key_hook(fdf->mlx_new_win, &deal_key, fdf);