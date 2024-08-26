/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:57:12 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/26 12:41:10 by yparthen         ###   ########.fr       */
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
		if (ft_strncmp(&file[len - 4], ".fdf", 4)== 0)
			return (1);
	}
	return (0);
}

/*	THIS FUNCTION OPEND THE FILE AND RETURNS THE FILE DESCRIPTOR	*/
int	open_file(char *file, int *fd)
{
	if (valid_file(file) == 0)
	{
		ft_putstr_fd("FDF: Error opening file: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\nIncorrect format. Expected <filename.fdf>\n", 2);
		return (0);
	}
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr_fd("FDF: Error opening file: ", 2);
		ft_putstr_fd(file, 2);
		if (errno == ENOENT)
			ft_putstr_fd("\nFile not found\n", 2);
		if (errno == EACCES)
			ft_putstr_fd("\nAcces not granted\n", 2);
		return (0);
	}
	return (*fd);
}

/*	THIS FUNCION COUNTS THE NUMBER OF ROWS IN THE FILE	*/
static int	get_height(char	*y_file)
{
	int	y;
	char	*y_line;
	int	fd;

	y = 0;
	fd = open(y_file, O_RDONLY);
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
static int	get_width(char *x_file)
{
	int	temp_len;
	int	str_len;
	char *x_line;
	int	fd;
	
	fd = open(x_file, O_RDONLY);
	x_line = get_next_line(fd);
	if (!x_line)
		return (ft_putstr_fd("FDF: Error get_width()\n", 2), 0);
	else
	{
		str_len = ft_wc(x_line);
		while (x_line)
		{
			temp_len = ft_wc(x_line);
			free(x_line);
			if (temp_len != str_len)
				return (0); 
			x_line = get_next_line(fd);
		}
		if (x_line)
			free(x_line);
	}
	close(fd);
	return (str_len);
}

/*	THIS FUNCION READS THE FILE AND MALLOC AND 3D ARRAY		*/
/*	WITH INFORMATION OF THE FILE: X, Y AND Z COORDINATES	*/
int parse_file(char *file, t_fdf *fdf)
{
    int fd;
    int k;
	
    if (open_file(file, &fd) == 0) 
		ft_clear(fdf, 1, 1);
    fdf->height = get_height(file);
    fdf->width = get_width(file);
    if (fdf->height < 1 || fdf->width < 2)
		fatal_error("FDF: Wrong file format\n", fdf);
    fdf->map = ft_calloc((fdf->height + 1), sizeof(char **));
    if (fdf->map == NULL) 
		fatal_error("FDF: Error malloc()\n", fdf);
	k = 0;
	while (k < fdf->height)
	{
        fdf->map[k] = ft_calloc((fdf->width + 1), sizeof(char *));
        if (fdf->map[k] == NULL)
			fatal_error("FDF: Error malloc()\n", fdf);
		k++;
	}
    if (get_map(fdf, fd) != 0)
		ft_clear(fdf, 1, 1);
    close(fd);
    return 0;
}