/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:24:12 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:23:48 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(const char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return ((write(1, s, ft_strlen(s))));
}
