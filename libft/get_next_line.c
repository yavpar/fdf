/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yparthen <yparthen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:21:14 by yparthen          #+#    #+#             */
/*   Updated: 2024/03/24 10:24:38 by yparthen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remain_chars(t_list **list)
{
	int		i;
	int		k;
	char	*buffer;
	t_list	*last_node;
	t_list	*stash;

	k = 0;
	stash = malloc(sizeof(t_list));
	if (stash == NULL)
		return ;
	last_node = ft_lstlast(*list);
	while (last_node->content[k])
		k++;
	i = len_to_newl(last_node);
	buffer = malloc(sizeof(char) * (k - i + 1));
	if (buffer == NULL)
		return ;
	k = 0;
	while (last_node->content[i])
		buffer[k++] = last_node->content[i++];
	buffer[k] = '\0';
	stash->content = buffer;
	stash->next = NULL;
	free_list(list, stash, buffer);
}

void	concat_list(t_list **list, char *buffer)
{
	t_list	*add_queue;
	t_list	*n_node;

	n_node = malloc(sizeof(t_list));
	if (n_node == NULL)
		return ;
	add_queue = ft_lstlast(*list);
	if (add_queue == NULL)
		*list = n_node;
	else
		add_queue->next = n_node;
	n_node->content = buffer;
	n_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	while (!is_new_line(*list))
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = '\0';
		concat_list(list, buffer);
	}
}

char	*get_line(t_list *buffer)
{
	char	*line;
	int		str_len;

	if (buffer == NULL)
		return (NULL);
	str_len = len_to_newl(buffer);
	line = malloc((str_len + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	copy_list_to_str(buffer, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*buffer = NULL;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &new_line, 0 < 0))
		return (NULL);
	create_list(&buffer, fd);
	if (buffer == NULL)
		return (NULL);
	new_line = get_line(buffer);
	remain_chars(&buffer);
	return (new_line);
}
