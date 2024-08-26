/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:41:36 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 14:09:48 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Iterates a list and creates a new list which is the result		*/
/*	of the aplication of a function to each node of the list		*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_node;

	if (!lst)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		if (!f)
			n_node = ft_lstnew(lst->content);
		else
			n_node = ft_lstnew(f(lst->content));
		if (!n_node)
		{
			ft_lstclear(&n_node, del);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, n_node);
		lst = lst->next;
	}
	return (n_lst);
}
