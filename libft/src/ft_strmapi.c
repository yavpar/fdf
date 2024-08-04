/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:23:14 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/04 11:11:48 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	k;

	if (!s || !f)
		return (ft_strdup(""));
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	k = 0;
	while (*(s + k))
	{
		*(p + k) = f(k, *(s + k));
		k++;
	}
	*(p + k) = '\0';
	return (p);
}
/* Iterates a string and for each character a function is applied.	  */
/* The result of the funcion is saved in a pointer and the adresse is */
/* saved in returned string.										  */
