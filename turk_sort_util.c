/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:52:31 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/17 15:14:06 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

size_t	target_a_index(t_stack *a, int b_value)
{
	size_t	a_index;

	a_index = 0;
	while (a)
	{
		if (a->value > b_value)
			return (a_index);
		a_index++;
		a = a->next;
	}
	return (0);
}

static bool	r_execution(t_stack **a, t_stack **b, t_target best)
{
	while (best.rr-- > 0)
	{
		if (!rr(a, b))
			return (false);
	}
	while (best.ra-- > 0)
	{
		if (!ra(a))
			return (false);
	}
	while (best.rb-- > 0)
	{
		if (!rb(b))
			return (false);
	}
	return (true);
}

static bool	rr_execution(t_stack **a, t_stack **b, t_target best)
{
	while (best.rrr-- > 0)
	{
		if (!rrr(a, b))
			return (false);
	}
	while (best.rra-- > 0)
	{
		if (!rra(a))
			return (false);
	}
	while (best.rrb-- > 0)
	{
		if (!rrb(b))
			return (false);
	}
	return (true);
}

bool	turk_execution(t_stack **a, t_stack **b, t_target best)
{
	if (!r_execution(a, b, best))
		return (false);
	if (!rr_execution(a, b, best))
		return (false);
	if (!pa(a, b))
		return (false);
	return (true);
}
