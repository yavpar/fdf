/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:35:39 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:24:22 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned(unsigned int u)
{
	int	div;
	int	k;

	k = 0;
	div = 1;
	while (u / div >= 10)
		div *= 10;
	while (div > 0)
	{
		k += ft_putchar((u / div) + '0');
		u %= div;
		div /= 10;
	}
	return (k);
}
