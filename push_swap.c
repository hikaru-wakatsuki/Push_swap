/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:49:30 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/16 21:37:58 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static bool	two_stack(t_stack **a, int min, int max)
{
	if (min == (*a)->value)
		return (true);
	else
	{
		ft_swap((*a)->value, ((*a)->next->value));
		if (ft_printf("sa\n") < 0)
			return (false);
	}
	return (true);
}

bool	three_stack(t_stack **a, int min, int max)
{
	if ((*a)->value == max)
	{
		if (!ra(a))
			return (false);
		if (!two_stack(a, min, max))
			return (false);
	}
	else if ((*a)->next->value == max)
	{
		if (!rra(a))
			return (false);
		if (!two_stack(a, min, max))
			return (false);
	}
	else
	{
		if (!two_stack(a, min, max))
			return (false);
	}
	return (true);
}

int	find_min(t_stack *a)
{
	int	min;

	min = INT_MAX;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

static bool	four_or_five_stack(t_stack **a, int min, int max, size_t count)
{
	t_stack	*b;

	b = NULL;
	if (!bring_min_to_top(a, min, count))
		return (false);
	if (!pb(a, &b))
		return (false);
	if (count == 5)
	{
		if (!bring_min_to_top(a, find_min(*a), count - 1))
			return (false);
		if (!pb(a, &b))
			return (false);
	}
	if (!three_stack(a, find_min(*a), max))
		return (false);
	if (!pa(a, &b))
		return (false);
	if (count == 5)
	{
		if (!pa(a, &b))
			return (false);
	}
	return (true);
}

bool	push_swap(t_stack **a, int min, int max, size_t count)
{
	if (count == 2)
	{
		if (!two_stack(a, min, max))
			return (false);
	}
	if (count == 3)
	{
		if (!three_stack(a, min, max))
			return (false);
	}
	if (count <= 5)
	{
		if (!four_or_five_stack(a, min, max, count))
			return (false);
	}
	else
	{
		if (!over_five_stack(a, min, max, count))
			return (false);
	}
	return (true);
}
