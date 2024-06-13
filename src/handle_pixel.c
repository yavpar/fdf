/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:38:38 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/10 19:57:48 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(char *s)
{
	int	color;
	int	pos;
	
	pos = ft_char_in_str(s, ',')
	if (pos)
	{
			
	}
		if (za > 0)
		color = 0xFFFF00;
	else if (za < 0)
		color = 0xe80c0c;
	else
		color = 0xff00ff;
}

t_point	set_data_point(int x, int y, t_fdf *fdf)
{
	t_point	p;
	
	p.x = x;
	p.y = y;
	p.z = atoi(fdf->map[y][x]);
	p.color = get_color(fdf[y][x]);
}


#include "fdf.h"

void *draw(t_fdf *fdf) {
    int x, y;
    t_3d *p, *px, *py;

    mlx_clear_window(fdf->my_mlx, fdf->my_mlx_new_win);
    y = 0;
    while (y < fdf->height) {
        x = 0;
        while (x < fdf->width) {
            if (fdf->map[y][x] == NULL) {
                ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x);
                return NULL;
            }
            p = data_point(x, y, fdf->map[y][x]);
            if (p == NULL) {
                ft_printf("Error: data_point devolvió NULL para (%d, %d).\n", x, y);
                return NULL;
            }

            if ((x + 1) < fdf->width) {
                if (fdf->map[y][x + 1] == NULL) {
                    ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y, x + 1);
                    free(p);
                    return NULL;
                }
                px = data_point(x + 1, y, fdf->map[y][x + 1]);
                if (px == NULL) {
                    ft_printf("Error: data_point devolvió NULL para px (%d, %d).\n", x + 1, y);
                    free(p);
                    return NULL;
                }
                bresenham(p, px, fdf);
                free(px);
            }

            if ((y + 1) < fdf->height) {
                if (fdf->map[y + 1][x] == NULL) {
                    ft_printf("Error: fdf->map[%d][%d] es NULL.\n", y + 1, x);
                    free(p);
                    return NULL;
                }
                py = data_point(x, y + 1, fdf->map[y + 1][x]);
                if (py == NULL) {
                    ft_printf("Error: data_point devolvió NULL para py (%d, %d).\n", x, y + 1);
                    free(p);
                    return NULL;
                }
                bresenham(p, py, fdf);
                free(py);
            }

            free(p);
            x++;
        }
        y++;
    }
    return NULL;
}

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
}

int get_map(t_fdf *fdf, int fd) {
    int x, y;
    char *line;
    char **map_line;

    y = 0;
    while ((line = get_next_line(fd))) {
        map_line = ft_split(line, ' ');
        free(line);
        if (!map_line) return (free(fdf->map), 1);

        for (x = 0; map_line[x]; x++) {
            fdf->map[y][x] = ft_strdup(map_line[x]);
            if (fdf->map[y][x] == NULL) {
                free(map_line);
                destroy_map(fdf);
                return 1;
            }
        }
        fdf->map[y][x] = NULL;
        free(map_line);
        y++;
    }
    fdf->map[y] = NULL;
    return 0;
}

void destroy_map(t_fdf *fdf) {
    int y, x;

    if (fdf->map) {
        for (y = 0; y < fdf->height; y++) {
            if (fdf->map[y]) {
                for (x = 0; x < fdf->width; x++) {
                    if (fdf->map[y][x]) {
                        free(fdf->map[y][x]);
                    }
                }
                free(fdf->map[y]);
            }
        }
        free(fdf->map);
    }
}
