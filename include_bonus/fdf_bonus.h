/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:21:36 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/03 21:41:19 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# define PI 3.141592653589793
# define WIDTH 1500
# define HEIGHT 1024
# define ZOOM_FACTOR 400
# define BUFFER 1024
# define TEXT 0x76d7c4 //1f618d//ddbe43
# define BLACK 0x000000
# define WHITE 0xffffff

typedef struct 	s_2d
{
	int			x;
	int			y;
}				t_2d;

typedef struct s_3d
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_3d;

typedef struct s_matrix
{
	t_3d	i;
	t_3d	j;
	t_3d	k;
}			t_matrix;

typedef struct	s_limits
{
	t_2d		min;
	t_2d		max;
}				t_limits;

typedef struct s_bresenham
{
	float	dx;
	float	dy;
	float	x_incr;
	float	y_incr;
	int		i;
	int		pixel;
	int		steps;
}			t_bresenham;

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct s_fdf
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			line_len;
	int			endian;	
	char		***map;
	int			width;
	int			height;
	t_limits	borders;
	int			min;
	int			max;
	float		zoom;
	float		move_x;
	float		move_y;
	float		ang_x;
	float		ang_y;
	float		ang_z;
	int			iso;
	int			rotation;
	int			bonus;
	int			left_view;
	int			right_view;
	float		pad;
}			t_fdf;

/*	FOR PARSING FILE	*/
int			open_file(char *file, int *fd);
int			parse_file(char *file, t_fdf *fdf);
int			valid_entry(char *data);
int			get_map(t_fdf *fdf, int fd);

/*	FOR INITIALIZE THE WINDOW	*/
void		ft_mlx_init(t_fdf *fdf, char *file);
void 		init_variables(t_fdf *fdf);

/*	FOR DRAW LINES	*/
int			draw(t_fdf *fdf);
t_3d		to_iso(t_3d v, t_fdf *fdf);
int			get_color(char *s, t_fdf *fdf);
int 		interpolate_color(int color1, int color2, float factor);
void		clear_image(t_fdf *fdf);
void 		pixel_put_to_image(t_fdf *fdf, int x, int y, int color);

/*	FOR INTERACT WITH THE PROGRAM	*/
int			input(int keysym, t_fdf *fdf);
int			button_x_close(t_fdf *fdf);
int			esc_close(int keysym, t_fdf *fdf);
void		draw_menu(t_fdf *fdf);

/*	FOR CLEANNIG THE WINDOW AND FREE MEMORY		*/
void		ft_clear(t_fdf *fdf, int is_exit, int exit_code);
void		destroy_map(t_fdf *fdf);
void		fatal_error(char *str, t_fdf *fdf);

#endif