/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:13:39 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 12:28:42 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	k;

	if (!dest && !src)
		return (NULL);
	if (dest == src || !n)
		return (dest);
	k = 0;
	while (k < n)
	{
		*(char *)(dest + k) = *(const char *)(src + k);
		k++;
	}
	return (dest);
}
/* Copies n bytes from src to dest and returns the string copied */
/* it might overlaps */
