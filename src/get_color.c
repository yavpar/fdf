/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:29:01 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/16 18:21:52 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	merge_color(int color);
static int	interpolate(int first, int last, float delta);

int	get_color(char *s)
{
	int	k;

	k = ft_char_in_str(s, ',');
	if (k)
	{
		k++;
		if (s[k] && ((s[k] == '0' && (s[k + 1]) == 'x') || (s[k + 1] == 'X')))
		return(merge_color(ft_htoi(&s[k])));
	}
	k = ft_atoi(s);
	if (k == 0)
		return (0x0000ff);
	else
		return(0xFF00FF);
}

int	grad(int color_pa, int color_pb, float delta)
{
	int		r;
	int		g;
	int		b;

	r = interpolate(((color_pa >> 16) & 0xFF) ,(color_pb >> 16) & 0xFF, delta);
	g = interpolate(((color_pa >> 8) & 0xFF) ,(color_pb >> 8) & 0xFF, delta);
	b = interpolate(color_pa & 0xFF ,color_pb & 0xFF, delta);
	return ((r << 16) | (g << 8) | b);
}

static int	merge_color(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0XFF;
	g = (color >> 8) & 0XFF;
	b = color & 0XFF;
	return ((r << 16) | (g << 8) | b);
}

static int	interpolate(int first, int last, float delta)
{
	return (first + ((last - first) * delta));
}


// int map_value_to_color(int value, int min, int max)
// {
// 	float	ratio;
// 	int		color_start;
// 	int		color_end;

// 	color_start = 0x000000;
// 	color_end = 0xFFFFFF;
// 	ratio = (float)(value - min) / (max - min);
// 	return (interpolate_color(color_start, color_end, ratio));
// }

