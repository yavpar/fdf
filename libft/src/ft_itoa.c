/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:15:32 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 14:06:51 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Takes an integer and returns a string with the number in it	*/
static int	size_int(int n)
{
	int	n_size;

	n_size = 1;
	if (n < 0)
	{
		n_size++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		n_size++;
	}
	return (n_size);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		nbr;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = size_int(n);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (len > -1)
	{
		s[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
