/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 07:00:31 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 19:02:59 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char const c)
{
	size_t	count;
	size_t	n;

	count = 0;
	n = 0;
	while (*s)
	{
		if (*s == c && n != 0)
		{
			count++;
			n = 0;
		}
		else if (*s != c)
			n++;
		s++;
	}
	if (n != 0)
		count++;
	return (count);
}
