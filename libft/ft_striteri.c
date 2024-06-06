/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:05:37 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/04 11:08:00 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	k;

	if (!s || !f)
		return ;
	k = 0;
	while (*(s + k))
	{
		f(k, s + k);
		k++;
	}
}
/* Loops through a string and applies a funcion to each caracter */
