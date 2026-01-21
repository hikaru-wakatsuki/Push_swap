/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:48:41 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/21 19:50:58 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	sb(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return (true);
	ft_swap(&((*b)->value), &((*b)->next->value));
	return (true);
}

bool	pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!a || !*a)
		return (true);
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
	return (true);
}

bool	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return (true);
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	return (true);
}

bool	rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return (true);
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	return (true);
}
