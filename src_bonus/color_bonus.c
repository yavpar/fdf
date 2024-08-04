/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:48:29 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/02 14:27:21 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

/*	THIS FUNCION MERGES A COLOR */
static int	merge_color(int color)
{
	t_color	res_color;

	res_color.red = (color >> 16) & 0XFF;
	res_color.green = (color >> 8) & 0XFF;
	res_color.blue = color & 0XFF;
	return ((res_color.red << 16) | (res_color.green << 8) | res_color.blue);
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
/*	BETWEEN RED AND BLUE IF THE FILE HAS A COLOR IT RETURNS IT 		*/
int	get_color(char *s, t_fdf *fdf)
{
	int	k;
	float factor;
	int color1;
	int color2;
	
	// color1 = 0xCCFFFF;
	// color2 = 0xFF99CC;
	color1 = 0x0000ff;
	color2 = 0xff0000;
	k = ft_char_in_str(s, ',');
	if (k)
	{
		k++;
		return (merge_color(ft_htoi(&s[k])));
	}
	if (fdf->max == fdf->min) 
		return (color2);
	factor = (float)(ft_atoi(s) - fdf->min) / (fdf->max - fdf->min);
	return (interpolate_color(color1, color2, factor));
}
