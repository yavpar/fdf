/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:23:19 by yparthen          #+#    #+#             */
/*   Updated: 2024/08/16 13:05:00 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_err(int n, char *s, ...)
{
	va_list	args;
	int		i;
	char 	*str;

	i = 0;
	if (n < 1 || !s)
		return ;
	va_start(args, s);
	while (i < n)
	{
		str = va_arg(args, char *);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		i++;		
	}
	va_end(agrs);
}



// while (liste chaine avec les caracteres)
// {
// 	if (caracter "()")
// 		function qui omets les caracteres
// 	else if (caracter "<" ">" "<<" ">>")
// 		function qui gere les fds;
// 	else if (caracter "commande")
// 		function qui gere les commandes;
// 	else if (caracter "args")
// 		funcion qui gere et concatene les arguments et/ou les flags;
// 	else if (ansi suite)
// 		...
// }
