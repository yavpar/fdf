

#ifndef	FDF_H
#define	FDF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_fdf
{
	char **map;
	int	width;
	int	height;
	int	color;
}				t_fdf;

int				open_file(char *file, int *fd, t_fdf *fdf);
int				get_height(char *file);
int				get_map(t_fdf *fdf, int fd);
void			destroy_map(t_fdf *fdf);
int				get_map(t_fdf *fdf, int fd);
int				parse_file(char *file, t_fdf *fdf);

#endif
