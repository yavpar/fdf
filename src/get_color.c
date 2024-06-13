/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:29:01 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/13 13:07:22 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int map_value_to_color(int value, int min, int max)
{
	float	ratio;
	int		color_start;
	int		color_end;

	color_start = 0x000000;
	color_end = 0xFFFFFF;
	ratio = (float)(value - min) / (max - min);
	return (interpolate_color(color_start, color_end, ratio));
}

int	get_color(char *s, t_fdf *fdf)
{
	int	k;

	k = ft_char_in_str(s, ',');
	if (k)
	{
		k++;
		if (s[k] && ((s[k] == '0' && (s[k + 1]) == 'x' || s[k + 1] == 'X')))
		return(merge_color(ft_htoi(&s[k])));
	}
	return(map_value_to_color(ft_atoi(&s[k])), fdf->min, fdf->max);
}

int	merge_color(int color);
{
	int	r;
	int	b;
	int	b;

	r = (color >> 16) & 0XFF;
	g = (color >> 8) & 0XFF;
	b = color & 0XFF;
}
int	interpolate(int first, int last, float d)
{
	return (first + ((last - first) * ratio));
}

int	grad(int color_pa, int color_pb, float delta)
{
	int		r;
	int		g;
	int		b;

	r = interpolate(((color_pa >> 16) & 0xFF) ,(color_pb >> 16) & 0xFF, d);
	g = interpolate(((color_pa >> 8) & 0xFF) ,(color_pb >> 8) & 0xFF, d);
	b = interpolate(color_pa & 0xFF ,color_pb & 0xFF, d);
	return ((r << 16) | (g << 8) | b);
}