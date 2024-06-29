/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:39 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/29 18:39:01 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//static int	handle_no_event(void);
//static int	handle_input(int keysym, t_fdf *fdf);
// static int	deal_key(int key);

// static int	deal_key(int key)
// {

// 	ft_printf("%d\n", key);
// 	return (0);
// }

// static int	handle_no_event(void)
// {
// 	return (0);
// }

static int	handle_input(int keysym, t_fdf *fdf)
{
	ft_printf("%d\n", keysym);
	if (keysym == 65362 || keysym == 122)
		fdf->move_y -= 10;//up
	if (keysym == 65364 || keysym == 115)
		fdf->move_y += 10;//down;
	if (keysym == 65363 || keysym == 100)
		fdf->move_x += 10;//right;
	if (keysym == 65361 || keysym == 113)
		fdf->move_x -= 10;//left;
	if (keysym == 65451)
		fdf->zoom += 10;
	if (keysym == 65453)
		fdf->zoom -= 10;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(fdf->my_mlx, fdf->my_mlx_new_win);
		destroy_map(fdf);
		free(fdf->my_mlx);
		exit (0);
	}
	mlx_clear_window(fdf->my_mlx, fdf->my_mlx_new_win);
	draw(fdf);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	(void)av;
	if (ac != 2)
		return (1);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (1);
	parse_file(av[1], fdf);
	print_map(fdf->map);
	fdf->zoom = 0.5;
	fdf->move_x = 3.0;
	fdf->move_y = 3.0;
	fdf->angle = 0.01;
	fdf->my_mlx = mlx_init();
	//fdf->data_add = mlx_get_data_addr();
	fdf->my_mlx_new_win = mlx_new_window(fdf->my_mlx, 1800, 1800, "New Window");
	draw(fdf);
	//mlx_loop_hook(fdf->my_mlx, &deal_key, fdf);
	//mlx_key_hook(fdf->my_mlx_new_win, &deal_key, fdf);
	mlx_key_hook(fdf->my_mlx_new_win, &handle_input, fdf);
	mlx_loop(fdf->my_mlx);

	mlx_destroy_window(fdf->my_mlx, fdf->my_mlx_new_win);
	destroy_map(fdf);
	free(fdf->my_mlx);
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
