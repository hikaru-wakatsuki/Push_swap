/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:43:01 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/22 13:46:58 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../includes/push_swap.h"
#include "../libft/libft.h"

bool	input_and_control(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!line)
			return (true);
		if (!stack_control(a, b, line))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (false);
}

bool	checker(t_stack **a, t_stack **b, size_t count)
{
	size_t	i;
	t_stack	*cur;

	i = 1;
	if (!*a)
		return (false);
	cur = *a;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
		{
			stack_free(a);
			stack_free(b);
			return (false);
		}
		cur = cur->next;
		i++;
	}
	stack_free(a);
	if (count != i || *b != NULL)
	{
		stack_free(b);
		return (false);
	}
	return (true);
}
