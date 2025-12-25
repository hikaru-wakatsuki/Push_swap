/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 07:02:05 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/25 07:04:08 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	s_len;
	size_t	i;
	char	*dup;

	s_len = ft_strlen(s);
	if (n > s_len)
		n = s_len;
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	dup[n] = '\0';
	i = 0;
	while (*s && i < n)
	{
		*(dup++) = *(s++);
		i++;
	}
	dup -= n;
	return (dup);
}
