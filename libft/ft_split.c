/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:14:31 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 19:05:34 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	insert_word(char const *s, char **to_split, size_t to_index,
		size_t n)
{
	to_split[to_index] = ft_strndup(s - n, n);
	if (!(to_split[to_index]))
	{
		while (to_index--)
			free(to_split[(to_index)]);
		free(to_split);
		return (false);
	}
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char	**to_split;
	size_t	n;
	size_t	to_index;

	to_split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!to_split)
		return (NULL);
	n = 0;
	to_index = 0;
	while (*s)
	{
		if (*s == c && n != 0)
		{
			if (!(insert_word(s, to_split, (to_index++), n)))
				return (NULL);
			n = 0;
		}
		else if (*(s++) != c)
			n++;
	}
	if (n != 0)
		if (!(insert_word(s, to_split, (to_index++), n)))
			return (NULL);
	to_split[to_index] = NULL;
	return (to_split);
}
