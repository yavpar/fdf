/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:36:27 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/06 10:31:16 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THIS FUNCTION CHECKS IF ITS A VALID CHARACTER	*/
static int	valid_chars(char data)
{
	char	*chars;

	chars = "0123456789abcdefxABCDEFX,";
	while (*chars != '\0')
	{
		if (*chars == data)
			return (1);
		chars++;
	}
	ft_putstr_fd("FDF: invalid character\n", 2);
	ft_printf("Not valid: %c\n", data);
	return (0);
}

/*	THIS FUNCION VERIFIES THAT THE FILE HAVE	*/
/*	VALID CHARACTERS FOR THE PROGRAM			*/
static int	valid_entry(char *data)
{
	long	val;

	val = ft_atol(data);
	if (val < INT_MIN || val > INT_MAX)
		return (0);
	if (*data == '-' || *data == '+')
		data++;
	while (*data != '\0')
	{
		if (valid_chars(*data) == 0)
			return (0);
		data++;
	}
	return (1);
}

static void	find_max_min(t_fdf *fdf, char *dest)
{
	int	val;

	val = ft_atoi(dest);
	if (val > fdf->max)
		fdf->max = val;
	else if (val < fdf->min)
		fdf->min = val;
}

static int	fill_map(char **dest, char **src, t_fdf *fdf)
{
	int	k;

	k = 0;
	while (src[k])
	{
		if (valid_entry(src[k]) == 0)
		{
			free(src[k]);
			free(src);
			ft_clear(fdf, 1, 1);
		}
		if (src[k][0] != ' ' && src[k][0] != '\n' && src[k] != NULL)
		{
			dest[k] = ft_strdup(src[k]);
			find_max_min(fdf, dest[k]);
			free(src[k]);
		}
		k++;
	}
	return (k);
}

/*	THIS FUNCION FILLS THE MAP */
int	get_map(t_fdf *fdf, char *file, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**map_line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	x = 0;
	while (line)
	{
		map_line = ft_split(line);
		if (map_line == NULL)
			return (ft_clear(fdf, 1, 1), 1);
		free(line);
		x = fill_map(fdf->map[y], map_line, fdf);
		free(map_line);
		fdf->map[y][x] = NULL;
		line = get_next_line(fd);
		y++;
	}
	fdf->map[y] = NULL;
	free(line);
	close(fd);
	return (0);
}
