/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_zero_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:30:07 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/23 18:50:44 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	space_print(int flag_count, int *count)
{
	while (flag_count > 0)
	{
		if (!ft_putchar_printf(' ', count))
			return (false);
		flag_count--;
	}
	return (true);
}

bool	zero_print(int flag_count, int *count)
{
	while (flag_count > 0)
	{
		if (!ft_putchar_printf('0', count))
			return (false);
		flag_count--;
	}
	return (true);
}

bool	space_print_malloc(int flag_count, int *count, char *buffer)
{
	while (flag_count > 0)
	{
		if (!ft_putchar_printf(' ', count))
		{
			free(buffer);
			return (false);
		}
		flag_count--;
	}
	return (true);
}

bool	zero_print_malloc(int flag_count, int *count, char *buffer)
{
	while (flag_count > 0)
	{
		if (!ft_putchar_printf('0', count))
		{
			free(buffer);
			return (false);
		}
		flag_count--;
	}
	return (true);
}
