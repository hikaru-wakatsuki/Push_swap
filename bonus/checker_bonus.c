/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:43:01 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/19 20:46:54 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../includes/push_swap.h"
#include "../libft/libft.h"

bool	input_and_control(t_stack **a, t_stack **b, size_t count)
{
	char	*line;

	if (count == 1)
		return (true);
	while (true)
	{
		line = get_next_line(0);
		if (!line)
			return (true);
		if (!stack_control(a, b, line))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (true);
}

bool	checker(t_stack *a, t_stack *b, size_t count)
{
	size_t	i;

	i = 1;
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
		i++;
	}
	if (count != i || b != NULL)
		return (false);
	return (true);
}
