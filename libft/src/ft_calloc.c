/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:26:09 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 14:03:54 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory, fills it with zeros and returns the pointer */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > 0 && INT_MAX / nmemb < size)
		return (NULL);
	if (size > 0 && INT_MAX / size < nmemb)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
