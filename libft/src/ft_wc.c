/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:54 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/04 14:52:41 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wc(char *s)
{
	int	state;
	int	out;
	int	in;
	int	wc;

	out = 0;
	wc = 0;
	in = 1;
	state = out;
	while (*s)
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
			state = out;
		else if (state == out)
		{
			state = in;
			wc++;
		}
		s++;
	}
	return (wc);
}
