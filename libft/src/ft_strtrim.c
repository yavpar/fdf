/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:49:14 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 12:57:46 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_in_set(const char *s, char chr)
{
	while (*s)
		if (*s++ == chr)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(""));
	begin = 0;
	end = ft_strlen(s1) - 1;
	while (ft_in_set(set, *(s1 + begin)))
		begin++;
	if (begin >= end)
		return (ft_strdup(""));
	while (ft_in_set(set, *(s1 + end)))
		end--;
	return (ft_substr(s1, begin, end - begin + 1));
}
/* Search at the begining and at the end of a string a set of characters */
/* and returns the new string without the separator*/
