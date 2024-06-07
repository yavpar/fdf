
#include "libft.h"

int	str_in_str(char *src, char *str)
{
	int	k;
	int	i;

	if (!src || !str)
		return (0);
	k = 0;
	while (src[k])
	{
		i = 0;
		while ((src[k + i] == str[i]) && str[i])
			i++;
		if (str[i] == '\0')
			return (1);
		k++;
	}
	return (0);
}
