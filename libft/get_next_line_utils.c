/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:52:40 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/22 14:11:08 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_and_free(char *s1, char *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	while (*s1)
		*(join++) = *(s1++);
	while (*s2)
		*(join++) = *(s2++);
	*join = '\0';
	free(s1 - s1_len);
	return (join - s1_len - s2_len);
}

t_gnl	*get_node(int fd, t_gnl **head)
{
	t_gnl	*node;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_gnl *)malloc(sizeof(t_gnl));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->content = NULL;
	node->next = *head;
	*head = node;
	return (node);
}

void	remove_node(int fd, t_gnl **head)
{
	t_gnl	*cur;
	t_gnl	*prev;

	prev = NULL;
	cur = *head;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (prev)
				prev->next = cur->next;
			else
				*head = cur->next;
			free(cur->content);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

bool	get_next_line_checker(char **line, bool check)
{
	if (check)
		return (true);
	else
	{
		free (line);
		return (false);
	}
}
