/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:48:06 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 12:46:59 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoind;
	size_t	k;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && *s2)
		return (ft_strdup(s2));
	if (*s1 && !s2)
		return (ft_strdup(s1));
	strjoind = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoind)
		return (NULL);
	k = 0;
	while (*s1)
		*(strjoind + k++) = *s1++;
	while (*s2)
		*(strjoind + k++) = *s2++;
	*(strjoind + k) = '\0';
	return (strjoind);
}
/* Joins s1 and s2 and returns the string created */
