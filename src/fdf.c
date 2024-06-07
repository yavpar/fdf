#include "fdf.h"

static void	print_map(char ***map)
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

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		return (1);
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (1);
	parse_file(av[1], fdf);
	print_map(fdf->map);
	destroy_map(fdf);
}

