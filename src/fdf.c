#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;
	int	k;
	int	i;

	if (ac != 2)
		return (1);
	fdf = (t_fdf *)malloc(sizeof(t_fdf *));
	if (fdf == NULL)
		return (1);
	parse_file(av[1], fdf);
ft_printf("FIN de PARSE FILE\n");
	k = 0;
	while (k < fdf->height)
	{
		i = 0;
		while (i < fdf->width)
		{
			if (fdf->map[k][i])
				ft_printf("%s", fdf->map[k][i]);
			else
				ft_printf("NO SE PUEDE LEER LA MATRIZ\n");
			i++;
		}
		k++;
	}
	destroy_map(fdf);
}


int	open_file(char *file, int *fd, t_fdf *fdf)
{
	if (ft_strnstr(file, ".fdf", 4) != NULL)
		return ((free(fdf), 0));
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return ((free(fdf), 0));
	return (*fd);
}

/*
void	fill_line(char *map, char **map_line)
{
	int	k;
	int	i;

	k = 0;
	while (map[k])
	{
		map[k] = map_line[i];
		k++;
	}
}
*/

int	get_map(t_fdf *fdf, int fd)
{
	int	x;
	int	y;
	char *line;
	char **map_line;
ft_printf("En get_map\n");

	line = get_next_line(fd);
	y = 0;
	while (y < fdf->height)
	{
		ft_printf("%s", line);
		x = 0;
		map_line = ft_split(line, ' ');
		if (fdf->map == NULL)
			return (free(fdf->map), 1);
		free(line);
		while (x < fdf->width)
		{
			line = map_line[x];
			fdf->map[y][x] = line[x];	
			x++;
		}
		fdf->map[y][x] = '\0';
		line  = get_next_line(fd);
		y++;
	}
	fdf->map[y] = '\0';
	free(line);
	return (0);
}

/*	This function counts the number of case in one line	*/
int	get_width(char *file)
{
	int	k;
	int	fd;
	char *line;
ft_printf("En get_width\n");

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	k = 0;
	line = get_next_line(fd);
	if (line)
	{
		k = ft_wc(line);
		free(line);
	}
	close(fd);
	return (k);
}

/*	This function counts the number of lines in the file	*/
int	get_height(char *file)
{
	int	fd;
	int	k;
	char *line;
ft_printf("En get_height\n");

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	k = 0;
	line = get_next_line(fd);
	if (line)
	{
		while (line)
		{
			k++;
			free(line);
			line = get_next_line(fd);
		}
		if (line)
			free(line);
	}
	close(fd);
	return (k);
}

/*	- Verifico la extencion del archivo ".fdf"	*/
/* 	- Calculo la talla del mapa Altura y Ancho	*/
/*	-*/
int	parse_file(char *file, t_fdf *fdf)
{
	int	fd;
	int	k;
ft_printf("En Parse_file\n");
	k = 0;
	if (open_file(file, &fd, fdf) == 0)
		exit (3);
	fdf->height = get_height(file);
	fdf->width = get_width(file);
	if (fdf->height <= 0 || fdf->width <= 0)
		exit(2);
	fdf->map = malloc(sizeof(char **) * (fdf->height + 1));	
	if (fdf->map == NULL)
		(free(fdf), exit (3));
	while (k < fdf->height)
	{
		fdf->map[k] = malloc(sizeof(char *) * (fdf->width + 1));
		if (fdf->map[k] == NULL)
			(ft_free_array((void **)fdf->map, k), exit(3));
		k++;
	}
	if (get_map(fdf, fd) != 0)
		(free(fdf), exit (1));
	return (0);
}
