/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:48:41 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/21 19:53:51 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	sa(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return (true);
	ft_swap(&((*a)->value), &((*a)->next->value));
	return (true);
}

bool	pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!b || !*b)
		return (true);
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
	return (true);
}

bool	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return (true);
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	return (true);
}

bool	rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return (true);
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	return (true);
}
