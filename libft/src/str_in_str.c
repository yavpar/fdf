/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_in_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:01:53 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/04 15:01:56 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_in_str(char *src, char *str)
{
	int	k;
	int	i;

	if (!src || !str)
		return (0);
	k = 0;
	while (src[k])
	{
		i = 0;
		while ((src[k + i] == str[i]) && str[i])
			i++;
		if (str[i] == '\0')
			return (1);
		k++;
	}
	return (0);
}
