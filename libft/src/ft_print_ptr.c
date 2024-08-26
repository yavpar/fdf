/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:44:25 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:23:42 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(void *ptr, t_flags *flags)
{
	int				k;
	unsigned long	p;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	k = 0;
	p = (unsigned long)ptr;
	k += write(1, "0x", 2);
	k += ft_print_hex(p, flags);
	return (k);
}
