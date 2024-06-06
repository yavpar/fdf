/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:48:36 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 14:11:06 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Compares 2 strings and retruns the diference	*/
/*	if n = 0 returns 0								*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					cmp;
	const unsigned char		*p1;
	const unsigned char		*p2;

	p1 = s1;
	p2 = s2;
	if (n == 0)
		return (n);
	while (n-- && *p1++ == *p2++)
		;
	cmp = *(--p1) - *(--p2);
	return (cmp);
}
