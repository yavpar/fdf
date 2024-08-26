/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:48:29 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/01 22:49:48 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	THIS FUNCION MERGES A COLOR */
static int	merge_color(int color)
{
	t_color	result_color;

	result_color.red = (color >> 16) & 0XFF;
	result_color.green = (color >> 8) & 0XFF;
	result_color.blue = color & 0XFF;
	return ((result_color.red << 16) | (result_color.green << 8) | result_color.blue);
}

/*	THIS FUNCTION RETURNS THE COLOR INTERPOLATED BETWEEN TWO COLORS	*/
int interpolate_color(int color1, int color2, float factor)
{
	t_color col1;
	t_color col2;
	t_color result;

	col1.red = (color1 >> 16) & 0xFF;
	col1.green = (color1 >> 8) & 0xFF;
	col1.blue = color1 & 0xFF;
	col2.red = (color2 >> 16) & 0xFF;
	col2.green = (color2 >> 8) & 0xFF;
	col2.blue = color2 & 0xFF;
	result.red = col1.red + factor * (col2.red - col1.red);
	result.green = col1.green + factor * (col2.green - col1.green);
	result.blue = col1.blue + factor * (col2.blue - col1.blue);
	return ((result.red << 16) | (result.green << 8) | result.blue);
}

/*	THIS FUNCION FINDS THE APROPIATED COLOR FOR ONE VECTOR POINT	*/
/*	IF THE FILE HAS A COLOR, OTHERWHISE RETURNS WHITE COLOR			*/
int	get_color(char *s, t_fdf *fdf)
{
	int	k;
	
	(void)fdf;
	k = ft_char_in_str(s, ',');
	if (k)
	{
		k++;
		return(merge_color(ft_htoi(&s[k])));
	}
	return (0xffffff);
}

