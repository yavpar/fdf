/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:21:38 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:24:42 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_list(t_list **list, t_list *stash, char *buffer)
{
	t_list	*p;

	if (*list == NULL)
		return ;
	while (*list)
	{
		p = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = p;
	}
	*list = NULL;
	if (stash->content[0])
		*list = stash;
	else
	{
		free(buffer);
		free(stash);
	}
}

int	len_to_newl(t_list *list)
{
	int	len;
	int	k;

	len = 0;
	if (list == NULL)
		return (len);
	while (list)
	{
		k = 0;
		while (list->content[k] && k < BUFFER_SIZE)
		{
			if (list->content[k] == '\n')
			{
				++len;
				return (len);
			}
			++k;
			++len;
		}
		list = list->next;
	}
	return (len);
}

int	is_new_line(t_list *list)
{
	int		k;
	t_list	*last_node;

	if (!list)
		return (0);
	k = 0;
	last_node = ft_lstlast(list);
	while (last_node->content[k] && k < BUFFER_SIZE)
	{
		if (last_node->content[k] == '\n')
			return (1);
		k++;
	}
	return (0);
}

void	copy_list_to_str(t_list *list, char *buffer)
{
	int	k;
	int	j;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			if (list->content[j] == '\n')
			{
				buffer[k++] = '\n';
				buffer[k] = '\0';
				return ;
			}
			buffer[k++] = list->content[j++];
		}
		list = list->next;
	}
	buffer[k] = '\0';
}
