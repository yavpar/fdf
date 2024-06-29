

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define PI 3.141592653589793

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
	float	angle;
	void	*my_mlx;
	void	*my_mlx_new_win;
	//void	*data_add;
	//void 	*mlx_img; // for mlx_new_image
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_fdf;

void		destroy_map(t_fdf *fdf);
int			bresenham(t_3d *pa, t_3d *pb, t_fdf *fdf);
void		draw(t_fdf *fdf);
void		get_points(int x1, int y1, int x2, int y2, t_fdf *fdf);
void		calcul_bresenham(t_bresenham *var, t_3d *p1, t_3d *p2);
void		draw_line(t_3d p1, t_3d p2, t_fdf *fdf);
void		draw_pixel_low(t_3d p1, t_3d p2, t_fdf *fdf);
void		draw_pixel_high(t_3d p1, t_3d p2, t_fdf *fdf);
void		projection_2d(t_3d *p);
t_3d		to_iso(t_3d v);
int			get_color(char *s);
int			grad(int color_pa, int color_pb, float delta);

/*		FOR PARSING DATA	*/
int			open_file(char *file, int *fd, t_fdf *fdf);
int			get_height(char *y_line);
int			get_width(char *x_line);
int			get_map(t_fdf *fdf, int fd);
int			parse_file(char *file, t_fdf *fdf);
int			get_map(t_fdf *fdf, int fd);
// void			data_point(int x, int y, char *s);

/*		NEW FONCTONS		*/
// t_2d			projection_2d(t_3d *p);
void		set_zoom(t_3d *p1, t_3d *p2, t_fdf *fdf);
void		set_move(t_3d *p1, t_3d *p2, t_fdf *fdf);
void		print_map(char ***map);

/*		POUTR CALCUL MATRICIELLE	*/
t_matrix			rot_matrix_x(float alpha);
// t_matrix			*rot_matrix_y(float alpha);
t_matrix			rot_matrix_z(float alpha);
float				grad_to_rad(float deg);
// t_matrix			matriz_id(void);
// t_3d				*to_iso(t_3d *v, t_fdf *fdf);
// t_3d				*mat_x_vec(t_matrix *m, t_3d *vt);
// enum	color_pos
// {
// 	0X00FFFF,0XAFEEEE, // BLUE
// 	0X00FF00,0XADFF2F, // GREEN
// 	0xFFFF00, 0xFFD700, // YELLOW, ORANGE
// 	0XFF0000, 0XCD5C5C // RED, INDIAN RED
// }		clr_pos;

// enum	color_neg
// {
// 	0X1E90FF, 0X0000FF // BLUE ,BLUE FONCE
// 	0X7B68EE, 0X4B0082 //MediumSlateBlue, INDIGO
// 	0XFF00FF, 0XDC143C// MAGENTA, Crimson
// 	0XFF1493, 0XC71585 // DEEP-PINK, MediumVioletRed
// }		clr_neg;
#endif
