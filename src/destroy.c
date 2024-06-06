

#include "fdf.h"

/*	This funcion cleans the map "char **""	*/
/*	and the structure fdf					*/
static void	free_split(char **s);

void	destroy_map(t_fdf *fdf)
{
	int	k;

	k = 0;
	if (fdf != NULL)
	{
		if (fdf->map != NULL)
		{
			while (fdf->map[k] != NULL)
			{
				free_split((char **)fdf->map[k]);
				free(fdf->map[k]);
				k++;
			}
			free(fdf->map);
			fdf->map = NULL;
		}
		free(fdf);
		fdf = NULL;
	}
}

static void	free_split(char **s)
{
	int	k;

	k = 0;
	if (s && *s)
	{
		while (s[k] != NULL)
		{
			free(s[k]);
			k++;
		}
		free(s);
		s = NULL;
	}
}
