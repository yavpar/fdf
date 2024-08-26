/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:39:33 by yparthen          #+#    #+#             */
/*   Updated: 2024/06/09 19:49:48 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_hex_digit(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') ||
		(c >= 'a' && c <= 'f');
}

int hex_value(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
	else if (c >= 'A' && c <= 'F')
		return 10 + (c - 'A');
    else if (c >= 'a' && c <= 'f')
		return 10 + (c - 'a');
	return -1;
}

long int	ft_htoi(char *hex_str)
{
    long int	result;
	int				i;
	
	if (!hex_str && (hex_str[0] != '0' || (hex_str[1] != 'x' && hex_str[1] != 'X')))
		return -1;
	result = 0;
	i = 0;
    hex_str += 2;
	while (i < 6)
	{
		if (!is_hex_digit(hex_str[i]))
			return -1;
		result = (result << 4) | hex_value(hex_str[i]);
		i++;
	}
	return result;
}