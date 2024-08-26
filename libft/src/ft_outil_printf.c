/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:30:16 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:22:56 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_parse_type(char type, t_flags *flags)
{
	if (type == 'd')
		flags->type = 'd';
	else if (type == 'i')
		flags->type = 'i';
	else if (type == 'c')
		flags->type = 'c';
	else if (type == 's')
		flags->type = 's';
	else if (type == 'u')
		flags->type = 'u';
	else if (type == 'p')
		flags->type = 'p';
	else if (type == 'x')
		flags->type = 'x';
	else if (type == 'X')
		flags->type = 'X';
	else if (type == '%')
		flags->type = '%';
}

static void	ft_parse_marks(const char s, t_flags *flags)
{
	if (s == ' ')
		flags->space = 1;
	else if (s == '+')
		flags->plus = 1;
	else if (s == '#')
		flags->hash = 1;
}

static int	ft_is_mark(char s)
{
	char	*mark;

	mark = "+# ";
	while (*mark)
	{
		if (*mark == s)
			return (1);
		mark++;
	}
	return (0);
}

static int	ft_is_type(char s)
{
	if (s == 'd' || s == 'i' || s == 's' || s == 'c' || s == 'p' || s == 'u'
		|| s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}

int	ft_parse_format_spec(const char *s, t_flags *flags)
{
	int	in_format;
	int	k;

	in_format = 1;
	k = 0;
	while (in_format && *(s + k) != '\0')
	{
		if (ft_is_mark(*(s + k)))
			ft_parse_marks(*(s + k), flags);
		else if (ft_is_type(*(s + k)))
		{
			ft_parse_type(*(s + k), flags);
			in_format = 0;
		}
		k++;
	}
	return (k);
}
