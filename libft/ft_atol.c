/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:06:45 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 14:02:50 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Take a string and returns un long type	*/
long	ft_atol(const char *nptr)
{
	long	nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	while ((*nptr && (*nptr >= 9 && *nptr <= 13)) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
		if (nptr == 0)
			return (0);
	}
	while (ft_isdigit(*nptr))
	{
		nbr = (10 * nbr) + *nptr - '0';
		nptr++;
	}
	return (nbr * sign);
}
