/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:07:13 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 14:03:02 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates a pointer and puts the zero value in it*/
void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n-- > 0)
	{
		*p = 0;
		p++;
	}
}
