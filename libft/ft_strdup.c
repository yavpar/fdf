/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:59:04 by yparthen          #+#    #+#             */
/*   Updated: 2023/12/04 11:07:45 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		l;
	char	*cpy;

	l = ft_strlen(s);
	if (!s)
		return (NULL);
	i = 0;
	cpy = (char *)malloc(sizeof(char) * l + 1);
	if (!cpy)
		return (NULL);
	while (i < l)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/* Returns a new string copied from s*/
