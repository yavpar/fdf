/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:56:47 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/29 17:07:47 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fill_map(char **dest, char **src, t_fdf *fdf);

// int get_map(t_fdf *fdf, int fd) {
//     int x, y;
//     char *line;
//     char **map_line;

//     y = 0;
//     while ((line = get_next_line(fd))) {
//         map_line = ft_split(line, ' ');
//         free(line);
//         if (!map_line) return (free(fdf->map), 1);

//         for (x = 0; map_line[x]; x++) {
//             fdf->map[y][x] = ft_strdup(map_line[x]);
//             if (fdf->map[y][x] == NULL) {
//                 free(map_line);
//                 destroy_map(fdf);
//                 return 1;
//             }
//         }
//         fdf->map[y][x] = NULL;
//         free(map_line);
//         y++;
//     }
//     fdf->map[y] = NULL;
//     return 0;
// }

// int get_map(t_fdf *fdf, int fd) {
//     int x, y;
//     char *line;
//     char **map_line;

//     y = 0;
//     while ((line = get_next_line(fd))) {
//         map_line = ft_split(line, ' ');
//         free(line);
//         if (!map_line) return (free(fdf->map), 1);

//         for (x = 0; map_line[x]; x++) {
//             fdf->map[y][x] = ft_strdup(map_line[x]);
//             if (fdf->map[y][x] == NULL) return (free(map_line), free(fdf->map), 1);
//         }
//         fdf->map[y][x] = NULL;
//         free(map_line);
//         y++;
//     }
//     fdf->map[y] = NULL;
//     return 0;
// }


int	get_map(t_fdf *fdf, int fd)
{
	int	x;
	int	y;
	char *line;
	char **map_line;

	fdf->max = INT_MIN;
	fdf->min = INT_MAX;
	line = get_next_line(fd);
	y = 0;
	x = 0;
	while (line)
	{
		map_line = ft_split(line, ' ');
		if (map_line == NULL)
			return (free(fdf->map), 1);
		free(line);
		x = fill_map(fdf->map[y], map_line, fdf);
		free(map_line);
		fdf->map[y][x] = NULL;
		line  = get_next_line(fd);
		y++;
	}
	fdf->map[y] = NULL;
	free(line);
	return (0);
}

static int	fill_map(char **dest, char **src, t_fdf *fdf)
{
	int	k;
	int	val;

	k = 0;
	while (src[k])
	{
		dest[k] = ft_strdup(src[k]);
		val = ft_atoi(dest[k]);
		if (val > fdf->max)
			fdf->max = val;
		if (val < fdf->min)
			fdf->min = val;
		free(src[k]);
		k++;
	}
	return (k);
}
