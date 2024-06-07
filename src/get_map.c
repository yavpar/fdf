
#include "fdf.h"

static int	fill_map(char **dest, char **src);

int	get_map(t_fdf *fdf, int fd)
{
	int	x;
	int	y;
	char *line;
	char **map_line;
	
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		map_line = ft_split(line, ' ');
		if (fdf->map == NULL)
			return (free(fdf->map), 1);
		free(line);
		x = fill_map(fdf->map[y], map_line);
		//while (map_line[x])
	//	{
	//		fdf->map[y][x] = ft_strdup(map_line[x]);
	//		free(map_line[x]);
	//		x++;
	//	}
		free(map_line);
		fdf->map[y][x] = NULL;
		line  = get_next_line(fd);
		y++;
	}
	fdf->map[y] = NULL;
	free(line);
	return (0);
}

static int	fill_map(char **dest, char **src)
{
	int	k;

	k = 0;
	while (src[k])
	{
		dest[k] = ft_strdup(src[k]);
		free(src[k]);
		k++;
	}
	return (k);
}
