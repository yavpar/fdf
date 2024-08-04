/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:17:05 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:24:28 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_args(va_list ap, t_flags *flags)
{
	int	k;

	k = 0;
	if (flags->type == 'c')
		k += ft_print_char(va_arg(ap, int));
	else if (flags->type == 's')
		k += ft_print_str(va_arg(ap, char *));
	else if (flags->type == 'd' || flags->type == 'i')
		k += ft_print_int(va_arg(ap, int), flags);
	else if (flags->type == 'u')
		k += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (flags->type == 'p')
		k += ft_print_ptr(va_arg(ap, void *), flags);
	else if (flags->type == 'x' || flags->type == 'X')
		k += ft_print_hex((unsigned long long)va_arg(ap, unsigned int), flags);
	else if (flags->type == '%')
		k += write(1, "%", 1);
	return (k);
}

static void	init_format_spec(t_flags *flags)
{
	flags->type = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			k;
	t_flags		flags;

	if (!fmt)
		return (-1);
	k = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		init_format_spec(&flags);
		if (*fmt == '%')
		{
				fmt++;
				fmt += ft_parse_format_spec(fmt, &flags);
				k += ft_print_args(ap, &flags);
		}
		else
		{
			k += write(1, fmt, 1);
			fmt++;
		}
	}
	va_end(ap);
	return (k);
}
