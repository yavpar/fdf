/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:11:50 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 12:30:07 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (d == s)
		return (dest);
	else if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
/* Copies n bytes from src to dest and returns the string copied */
/* not overlaps */
