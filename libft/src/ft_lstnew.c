/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:42:14 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/25 14:10:04 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Allocates and return a new node	*/
t_list	*ft_lstnew(void *content)
{
	t_list	*n_node;

	n_node = (t_list *)malloc(sizeof(t_list));
	if (!n_node)
		return (NULL);
	n_node->content = content;
	n_node->next = NULL;
	return (n_node);
}
