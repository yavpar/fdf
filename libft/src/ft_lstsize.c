/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:42:33 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 18:24:01 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Returns the length of a list	*/
int	ft_lstsize(t_list *lst)
{
	int	k;
ft_printf("in lstsize\n");

	k = 0;
	while (lst != NULL)
	{
		k++;
		lst = lst->next;
	}
ft_printf("fin de lstsize\n");
	return (k);
}
