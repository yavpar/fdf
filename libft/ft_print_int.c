/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:25:03 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:23:37 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write_int(int d)
{
	int				div;
	int				k;
	long long int	nb;

	div = 1;
	k = 0;
	nb = d;
	if (d == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		nb = -nb;
		k += ft_putchar('-');
	}
	while (nb / div >= 10)
		div *= 10;
	while (div > 0)
	{
		k += ft_putchar((nb / div) + '0');
		nb %= div;
		div /= 10;
	}
	return (k);
}

int	ft_print_int(int d, t_flags *flags)
{
	int	k;

	k = 0;
	if (d < 0)
		k += ft_write_int(d);
	else
	{
		if (flags->plus == 0 && flags->space == 0)
			k += ft_write_int(d);
		else
		{
			if (flags->space == 1)
				k += write(1, " ", 1);
			if (flags->plus == 1)
				k += write(1, "+", 1);
			k += ft_write_int(d);
		}
	}
	return (k);
}
