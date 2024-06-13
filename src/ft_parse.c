/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 23:49:07 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/12 12:25:45 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	std_color(char *);
static int	get_color(char *s);

// void	data_point(int x, int y, char *s)
// {
// 	t_3d	p;

// 	// p = malloc(sizeof(t_3d));
// 	// if (!p)
// 		//return(ft_printf("DATA_POINT: error malloc\n"), NULL);
// 	// p->x = 0;
// 	// p->y = 0;
// 	// p->z = 0;
// 	// p->color = 0;
// 	p.x = x;
// 	p.y = y;
// 	p.z = ft_atoi(s);
// 	p.color = get_color(s);
// 	return ((t_3d)&p);
// }

/*
t_3d *data_point(int x, int y, char *s) {
    t_3d *p;
    int k;

    if (s == NULL) {
        ft_printf("Error: La cadena es NULL en x=%d, y=%d.\n", x, y);
        return NULL;
    }

    p = malloc(sizeof(t_3d));
    if (!p) {
        ft_printf("Error: No se pudo asignar memoria para t_3d.\n");
        return NULL;
    }

    p->x = x;
    p->y = y;
    k = 0;

    if (ft_isdigit(s[k]) || s[k] == '-' || s[k] == '+') {
        p->z = ft_atoi(s + k);
        while (s[k] && (ft_isdigit(s[k]) || s[k] == '-' || s[k] == '+')) k++;
    } else {
        p->z = 0;
    }

    if (s[k] == ',') {
        p->color = get_color(s + k + 1);
    } else {
        p->color = 0xFFFFFF;
    }

    ft_printf("data_point: x=%d, y=%d, z=%d, color=0x%x\n", p->x, p->y, p->z, p->color);
    return p;
}*/

/*t_3d *data_point(int x, int y, char *s) {
    t_3d *p;
    int k;

    if (s == NULL) {
        ft_printf("Error: La cadena es NULL en x=%d, y=%d.\n", x, y);
        return NULL;
    }

    p = malloc(sizeof(t_3d));
    if (!p) {
        ft_printf("Error: No se pudo asignar memoria para t_3d.\n");
        return NULL;
    }

    p->x = x;
    p->y = y;
    k = 0;

    p->z = (ft_isdigit(s[k]) || s[k] == '-' || s[k] == '+') ? ft_atoi(s + k) : 0;
    while (s[k] && (ft_isdigit(s[k]) || s[k] == '-' || s[k] == '+')) k++;

    p->color = (s[k] == ',') ? get_color(s + k + 1) : 0xFFFFFF;

    ft_printf("data_point: x=%d, y=%d, z=%d, color=0x%x\n", p->x, p->y, p->z, p->color);
    return p;
}*/




// t_3d	*data_point(int x, int y, char *s)
// {
// 	t_3d	*p;
// 	int		k;

// 	k = 0;
// 	p = malloc(sizeof(t_3d));
// // ft_printf("cadena s = %s", s);
// 	if (!p | !s)
// 	{ 
// 		ft_printf("Cadena vacia\n");
// 		return (NULL);
// 	}
// 	p->x = x;
// 	p->y = y;
// 	if (ft_isdigit(s[k]) || (s[k] == '-' || s[k] == '+'))
// 	{
// 		p->z = ft_atoi(&s[k]);
// 		while (ft_isdigit(s[k] || s[k] == '-' || s[k] == '+'))
// 			k++;
// 	}
// 	if (s[k] == ',')
// 		k++;
// 	p->color = get_color(s + k);
// 	return (p);
// }

// static int	get_color(char *s)
// {
// 	int	red;
// 	int	green;
// 	int	blue;
// 	int color;
	
// 	while (*s != ',')
// 		s++;
// 	if (ft_strncmp(s, "0x", 2) || ft_strncmp(s, "0x", 2))
// 	{
// 		color = ft_htoi(s);
// 		red = (color >> 16) & 0XFF;
// 		green = (color >> 8) & 0XFF;
// 		blue = color & 0XFF;
// 		return (red << 16 | green << 8 | blue);
// 	}
// 	return (std_color(s));
// }

// static int	std_color(char *s)
// {
// 	int	color;
// 	int is_neg;
	
// 	is_neg = 0;
// 	color = ft_atoi(s);
// 	if (color < 0)
// 		is_neg = 1;
// 	if (is_neg)
// 		return (0xff00ff);
// 	else if (color == 0)
// 		return (0xffffff);
// 	return (0x00FFFF);
// }