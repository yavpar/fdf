/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:47:04 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/02 13:01:16 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_size;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	if (start >= s_size)
		return (ft_strdup(""));
	if (len + start > s_size)
		len = s_size - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
/* Returns a new string of length len from start */
