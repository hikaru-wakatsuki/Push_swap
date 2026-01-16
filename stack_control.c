/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:49:49 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/16 16:31:43 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static size_t	find_min_index(t_stack *a, int min)
{
	size_t	i;

	i = 0;
	while (a && a->value != min)
	{
		a = a->next;
		i++;
	}
	return (i);
}

bool	bring_min_to_top(t_stack **a, int min, size_t count)
{
	size_t	i;

	i = find_min_index(*a, min);
	if (i <= count / 2)
	{
		while ((*a)->value != min)
		{
			if (!ra(a))
				return (false);
		}
	}
	else
	{
		while ((*a)->value != min)
		{
			if (!rra(a))
				return (false);
		}
	}
	return (true);
}
