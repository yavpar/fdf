/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:41:19 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/04 11:10:54 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	dest_len = 0;
	src_len = ft_strlen((char *)src);
	while (size > 0 && *dest)
	{
		dest++;
		dest_len++;
		size--;
	}
	while (size-- > 1 && *src)
	{
		*dest++ = *src++;
	}
	if (size == 0 || !*src)
		*dest = '\0';
	return (src_len + dest_len);
}
/* Concatenates dans dest the source and returns the length of both*/
