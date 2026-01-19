/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:34:15 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/19 19:30:23 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

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

int	find_max(t_stack *a)
{
	int	max;

	max = INT_MIN;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

static int	find_median(t_stack *a, size_t count)
{
	t_stack	*cur;
	t_stack	*tmp;
	size_t	smaller;

	cur = a;
	while (cur)
	{
		smaller = 0;
		tmp = a;
		while (tmp)
		{
			if (tmp->value < cur->value)
				smaller++;
			tmp = tmp->next;
		}
		if (smaller == count / 2)
			return (cur->value);
		cur = cur->next;
	}
	return (a->value);
}

bool	initialize_pb(t_stack **a, t_stack **b, size_t *count, size_t *i)
{
	int	median;

	median = find_median(*a, *count);
	if ((*a)->value <= median)
	{
		if (!print_and_control(a, b, "pb"))
			return (false);
		(*i)++;
		(*count)--;
	}
	else
	{
		if (!print_and_control(a, b, "ra"))
			return (false);
	}
	return (true);
}
