/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:49:30 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 18:28:52 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static bool	two_stack(t_stack **a, int min)
{
	if (min == (*a)->value)
		return (true);
	else
	{
		ft_swap(&((*a)->value), &((*a)->next->value));
		if (ft_printf("sa\n") < 0)
			return (false);
	}
	return (true);
}

static bool	three_stack(t_stack **a, int min, int max)
{
	if ((*a)->value == max)
	{
		if (!ra(a))
			return (false);
		if (!two_stack(a, min))
			return (false);
	}
	else if ((*a)->next->value == max)
	{
		if (!rra(a))
			return (false);
		if (!two_stack(a, min))
			return (false);
	}
	else
	{
		if (!two_stack(a, min))
			return (false);
	}
	return (true);
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

static bool	over_five_stack(t_stack **a, int min, size_t count)
{
	t_stack	*b;
	size_t	i;

	b = NULL;
	i = 0;
	while (i < count - 3)
	{
		if (!initialize_pb(a, &b, count, &i))
			return (false);
	}
	if (!three_stack(a, find_min(*a), find_max(*a)))
		return (false);
	while (i > 0)
	{
		if (!turk_sort(a, &b, count - i, i))
			return (false);
		i--;
	}
	return (bring_min_to_top(a, min, count));
}

bool	push_swap(t_stack **a, int min, int max, size_t count)
{
	if (count == 1)
		return (true);
	if (count == 2)
		return (two_stack(a, min));
	if (count == 3)
		return (three_stack(a, min, max));
	if (count <= 5)
		return (four_or_five_stack(a, min, max, count));
	return (over_five_stack(a, min, count));
}
