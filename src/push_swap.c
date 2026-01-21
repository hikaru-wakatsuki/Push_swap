/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:49:30 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/21 19:31:32 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

static bool	two_stack(t_stack **a, t_stack **b, int min)
{
	if (min == (*a)->value)
		return (true);
	else
		return (print_and_control(a, b, "sa\n"));
}

static bool	three_stack(t_stack **a, t_stack **b, int min, int max)
{
	if ((*a)->value == max)
	{
		if (!print_and_control(a, b, "ra\n"))
			return (false);
		return (two_stack(a, b, min));
	}
	else if ((*a)->next->value == max)
	{
		if (!print_and_control(a, b, "rra\n"))
			return (false);
		return (two_stack(a, b, min));
	}
	else
		return (two_stack(a, b, min));
}

static bool	four_or_five_stack(t_stack **a, t_stack **b, size_t count)
{
	if (!bring_min_to_top(a, b, find_min(*a), count))
		return (false);
	if (!print_and_control(a, b, "pb\n"))
		return (false);
	if (count == 5)
	{
		if (!bring_min_to_top(a, b, find_min(*a), count - 1))
			return (false);
		if (!print_and_control(a, b, "pb\n"))
			return (false);
	}
	if (!three_stack(a, b, find_min(*a), find_max(*a)))
		return (false);
	if (!print_and_control(a, b, "pa\n"))
		return (false);
	if (count == 5)
		return (print_and_control(a, b, "pa\n"));
	return (true);
}

static bool	over_five_stack(t_stack **a, t_stack **b, int min, size_t count)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = count;
	while (i < count - 3)
	{
		if (!initialize_pb(a, b, &tmp, &i))
			return (false);
	}
	if (!three_stack(a, b, find_min(*a), find_max(*a)))
		return (false);
	while (i > 0)
	{
		if (!turk_sort(a, b, count - i, i))
			return (false);
		i--;
	}
	return (bring_min_to_top(a, b, min, count));
}

bool	push_swap(t_stack **a, int min, int max, size_t count)
{
	t_stack	*b;

	b = NULL;
	if (count == 1 || is_sorted(*a))
		return (true);
	if (count == 2)
		return (two_stack(a, &b, min));
	if (count == 3)
		return (three_stack(a, &b, min, max));
	if (count <= 5)
		return (four_or_five_stack(a, &b, count));
	return (over_five_stack(a, &b, min, count));
}
