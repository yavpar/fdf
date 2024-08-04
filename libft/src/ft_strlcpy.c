/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:00:32 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 12:51:20 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	k;
	size_t	src_size;

	k = 0;
	src_size = ft_strlen(src);
	if (size > 0)
	{
		while (*(src + k) && k < size - 1)
		{
			*(dest + k) = *(src + k);
			k++;
		}
		*(dest + k) = '\0';
	}
	return (src_size);
}
/* Copies the source dans dest and returns the length of source*/
