/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:21:36 by yparthen          #+#    #+#             */
/*   Updated: 2024/07/01 09:58:24 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define PI 3.141592653589793
# define WIDTH 1024
# define HEIGHT 820
# define MARGIN 0.8

typedef struct s_2d
{
	float	x;
	float	y;
}			t_2d;

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

typedef struct s_map_limits
{
	t_2d	min;
	t_2d	max;
}				t_map_limits;

typedef struct s_bresenham
{
	float	dx;
	float	dy;
	float	d;
	int		x_incr;
	int		y_incr;
	int		color;
	float	pixel;
}			t_bresenham;

typedef struct s_fdf
{
	char	***map;
	int		width;
	int		height;
	int		color;
	float	zoom;
	float	move_x;
	float	move_y;
	int		max;
	int		min;
	float	ang_x;
	float	ang_y;
	float	ang_z;
	void	*mlx;
	void	*mlx_new_win;
	void	*img;
	char 	*img_data;
	int		bpp;
	int		line_len;
	int		endian;
	int		rot_z;
	int		rot_up_down;
	int		iso;
}			t_fdf;

void		destroy_map(t_fdf *fdf);
int			bresenham(t_3d *pa, t_3d *pb, t_fdf *fdf);
void		draw(t_fdf *fdf);
void		get_points(int x1, int y1, int x2, int y2, t_fdf *fdf);
void		calcul_bresenham(t_bresenham *var, t_3d *p1, t_3d *p2);
void		draw_line(t_3d p1, t_3d p2, t_fdf *fdf);
void		render_image(t_fdf *fdf);
void		draw_pixel_low(t_3d p1, t_3d p2, t_fdf *fdf);
void		draw_pixel_high(t_3d p1, t_3d p2, t_fdf *fdf);
void		put_pixel(t_fdf *fdf, int x, int y, int color);
void		projection_2d(t_3d *p);
t_3d		to_iso(t_3d v, t_fdf *fdf);
int			get_color(char *s);
int			grad(int color_pa, int color_pb, float delta);

/*		FOR PARSING DATA	*/
int			open_file(char *file, int *fd, t_fdf *fdf);
int			get_height(char *y_line);
int			get_width(char *x_line);
int			get_map(t_fdf *fdf, int fd);
int			parse_file(char *file, t_fdf *fdf);
int			get_map(t_fdf *fdf, int fd);

/*		NEW FONCTONS		*/
void		set_zoom(t_3d *p1, t_3d *p2, t_fdf *fdf);
void		set_move(t_3d *p1, t_3d *p2, t_fdf *fdf);
void		center_n_scale(t_fdf *fdf);
void		print_map(char ***map);
void		ft_clear(t_fdf *fdf, int is_exit);
int			close_window(t_fdf *fdf);

/*		POUTR CALCUL MATRICIELLE	*/
t_matrix			rot_matrix_x(float alpha);
t_matrix			rot_matrix_y(float alpha);
t_matrix			rot_matrix_z(float alpha);
t_3d				rot_map(t_3d v, t_fdf *fdf);
float				grad_to_rad(float deg);

#endif
