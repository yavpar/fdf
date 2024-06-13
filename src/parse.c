/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:57:12 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/10 19:54:53 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int parse_file(char *file, t_fdf *fdf) {
    int fd;
    int k;

    if (open_file(file, &fd, fdf) == 0) exit(3);
    fdf->height = get_height(file);
    fdf->width = get_width(file);
    if (fdf->height <= 0 || fdf->width <= 0) (free(fdf), exit(3));

    fdf->map = malloc(sizeof(char **) * (fdf->height + 1));
    if (fdf->map == NULL) (free(fdf), exit(3));

    for (k = 0; k < fdf->height; k++) {
        fdf->map[k] = malloc(sizeof(char *) * (fdf->width + 1));
        if (fdf->map[k] == NULL) {
            destroy_map(fdf);
            exit(3);
        }
    }

    if (get_map(fdf, fd) != 0) {
        destroy_map(fdf);
        exit(1);
    }
    close(fd);
    return 0;
}


// int	parse_file(char *file, t_fdf *fdf)
// {
// 	int	fd;
// 	int	k;

// 	k = -1;
// 	if (open_file(file, &fd, fdf) == 0)
// 		exit (3);
// 	fdf->height = get_height(file);
// 	fdf->width = get_width(file);
// 	if (fdf->height <= 0 || fdf->width <= 0)
// 		(free(fdf), exit (3));
// 	fdf->map = malloc(sizeof(char **) * (fdf->height + 1));	
// 	if (fdf->map == NULL)
// 		(free(fdf), exit (3));
// 	while (++k < fdf->height)
// 	{
// 		fdf->map[k] = malloc(sizeof(char *) * (fdf->width + 1));
// 		if (fdf->map[k] == NULL)
// 			(destroy_map(fdf), exit(3));
// 	}
// 	if (get_map(fdf, fd) != 0)
// 		(destroy_map(fdf), exit (1));
// 	close(fd);
// 	return (0);
// }


int	open_file(char *file, int *fd, t_fdf *fdf)
{
	if (str_in_str(file, ".fdf") == 0)
	{
		ft_printf("Incorrect format. Expected <filename.fdf>\n");
		return ((free(fdf), 0));
	}
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		ft_printf("Error opening file:\n", file);
		ft_printf("Not found: <%s>\n", file);
		return ((free(fdf), 0));
	}
	return (*fd);
}

/*	This function counts the number of lines in the file	*/
int	get_height(char	*y_file)
{
	int	y;
	char *y_line;
	int	fd;

	y = 0;
	fd = open(y_file, O_RDONLY);
	if (fd == -1)
		return (y);
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
	close(fd);
	return (y);
}

/*	This function counts the number of case in one line	*/
int	get_width(char *x_file)
{
	int	x;
	char *x_line;
	int	fd;
	
	x = 0;
	fd = open(x_file, O_RDONLY);
	if (fd == -1)
		return (x);
	x_line = get_next_line(fd);
	if (x_line)
	{
		x = ft_wc(x_line);
		free(x_line);
	}
	close(fd);
	return (x);
}
