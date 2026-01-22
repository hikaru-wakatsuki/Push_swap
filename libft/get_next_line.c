/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:51:15 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/22 14:12:16 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*remain_content(char *content, bool *check)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*remain;

	i = 0;
	*check = true;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	len = ft_strlen(content);
	if (i == len)
		return (free(content), NULL);
	remain = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!remain)
	{
		*check = false;
		return (free(content), NULL);
	}
	j = 0;
	while (content[i])
		remain[(j++)] = content[(i++)];
	remain[j] = '\0';
	return (free(content), remain);
}

static char	*extract_line(char *content)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!content || !content[i])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static bool	read_until_newline(int fd, char **content)
{
	char	*buf;
	ssize_t	bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (false);
	bytes = 1;
	while (!ft_strchr(*content, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), false);
		buf[bytes] = '\0';
		*content = strjoin_and_free(*content, buf);
		if (!*content)
			return (free(buf), false);
	}
	return (free(buf), true);
}

static char	*content_initialize(char *content)
{
	if (!content)
	{
		content = (char *)malloc(sizeof(char) * 1);
		if (!content)
			return (NULL);
		content[0] = '\0';
	}
	return (content);
}

bool	get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*node;
	bool			check;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (false);
	*line = NULL;
	node = get_node(fd, &head);
	if (!node)
		return (false);
	node->content = content_initialize(node->content);
	if (!node->content)
		return (remove_node(fd, &head), false);
	if (!read_until_newline(fd, &(node->content)))
		return (remove_node(fd, &head), false);
	if (!node->content || node->content[0] == '\0')
		return (remove_node(fd, &head), true);
	*line = extract_line(node->content);
	if (!*line)
		return (remove_node(fd, &head), false);
	node->content = remain_content(node->content, &check);
	if (!node->content)
		remove_node(fd, &head);
	return (get_next_line_checker(line, check));
}
