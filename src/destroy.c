

#include "fdf.h"

/*	This funcion cleans the map "char **""	*/
/*	and the structure fdf					*/

void	destroy_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	if (fdf)
	{
		if (fdf->map)
		{
			while (++y < fdf->height)
			{
				x = -1;
				while (++x < fdf->width)
				{
					if (fdf->map[y][x])
						free(fdf->map[y][x]);
				}
				free(fdf->map[y]);
			}
			free(fdf->map);
		}
		free(fdf);
	}
}
