
#include "libft.h"

int	ft_wc(char *s)
{
	int state;
	int	out;
	int	in;
	int	wc;

	out = 0;
	wc = 0;
	in = 1;
	state = out;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
			state = out;
		else if (state == out)
		{
			state = in;
			wc++;
		}
		s++;
	}
	return (wc);
}
