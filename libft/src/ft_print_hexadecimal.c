/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:52:11 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:23:22 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa_digits(unsigned long long x, int base)
{
	int	k;

	k = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		x /= base;
		k++;
	}
	return (k);
}

static void	ft_print_hexa_rec(unsigned long long x, t_flags *flags)
{
	char	*base_hexa;

	if (flags->type == 'X')
		base_hexa = "0123456789ABCDEF";
	else
		base_hexa = "0123456789abcdef";
	if (x > 0)
	{
		ft_print_hexa_rec(x / 16, flags);
		ft_putchar(base_hexa[x % 16]);
	}
}

int	ft_print_hex(unsigned long long x, t_flags *flags)
{
	int	k;

	k = 0;
	if (x == 0)
		return (ft_putchar('0'));
	else
	{
		if (flags->hash == 1)
		{
			if (flags->type == 'X')
				k += write(1, "0X", 2);
			else
				k += write(1, "0x", 2);
		}
		ft_print_hexa_rec(x, flags);
	}
	return (ft_hexa_digits(x, 16) + k);
}
