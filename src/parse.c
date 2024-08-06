/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:57:12 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/06 10:22:41 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	THIS FUNCION VERIFIES THE NAME AND THE EXTENTION	*/
/*	OF THE FILE <FILENAME.FDF>							*/
static int	valid_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len > 4)
	{
		if (ft_strncmp(&file[len - 4], ".fdf", 4) == 0)
			return (1);
	}
	return (0);
}

/*	THIS FUNCTION OPEND THE FILE AND RETURNS THE FILE DESCRIPTOR	*/
int	open_file(char *file)
{
	int	fd;

	if (valid_file(file) == 0)
	{
		ft_putstr_fd("FDF: Error opening file: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\nIncorrect format. Expected <filename.fdf>\n", 2);
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("FDF: Error opening file: ", 2);
		ft_putstr_fd(file, 2);
		if (errno == ENOENT)
			ft_putstr_fd("\nFile not found\n", 2);
		if (errno == EACCES)
			ft_putstr_fd("\nAcces not granted\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

/*	THIS FUNCION COUNTS THE NUMBER OF ROWS IN THE FILE	*/
static int	get_height(char *file, int fd)
{
	int		y;
	char	*y_line;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	y_line = get_next_line(fd);
	if (y_line)
	{
		while (y_line)
		{
			free(y_line);
			y_line = get_next_line(fd);
			y++;
		}
		if (y_line)
			free(y_line);
	}
	else
		ft_putstr_fd("FDF: Error get_height()\n", 2);
	close(fd);
	return (y);
}

/*	THIS FUNCION COUNTS THE NUMBER OF COLUMNS	*/
static void	malloc_lines(t_fdf *fdf, char *file, int fd)
{
	char	*x_line;
	int		line_len;
	int		y;

	fd = open(file, O_RDONLY);
	x_line = get_next_line(fd);
	if (!x_line)
		fatal_error("FDF: Error gnl()\n", fdf);
	y = 0;
	while (y < fdf->height)
	{
		line_len = ft_wc(x_line);
		fdf->map[y] = ft_calloc((line_len + 1), sizeof(char *));
		if (fdf->map == NULL)
			fatal_error("FDF: Error malloc()\n", fdf);
		free(x_line);
		if (line_len > fdf->width)
			fdf->width = line_len;
		x_line = get_next_line(fd);
		y++;
	}
	if (x_line)
		free(x_line);
	close(fd);
}

/*	THIS FUNCION READS THE FILE AND MALLOC AND 3D ARRAY		*/
/*	WITH INFORMATION OF THE FILE: X, Y AND Z COORDINATES	*/
int	parse_file(char *file, t_fdf *fdf)
{
	int	fd;

	fd = -1;
	if (open_file(file) == 0)
		ft_clear(fdf, 1, 1);
	fdf->min = INT_MAX;
	fdf->max = INT_MIN;
	fdf->height = get_height(file, fd);
	fdf->width = 0;
	fdf->map = ft_calloc((fdf->height + 1), sizeof(char **));
	if (fdf->map == NULL)
		fatal_error("FDF: Error malloc()\n", fdf);
	malloc_lines(fdf, file, fd);
	if (get_map(fdf, file, fd) != 0)
		ft_clear(fdf, 1, 1);
	return (0);
}
