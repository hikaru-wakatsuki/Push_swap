/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:49:49 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 12:03:42 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	rr(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	if (ft_printf("rr\n") < 0)
		return (false);
	return (true);
}

bool	rrr(t_stack **a, t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (ft_printf("rrr\n") < 0)
		return (false);
	return (true);
}

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
