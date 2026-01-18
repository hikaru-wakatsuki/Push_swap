/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:48:41 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 12:03:37 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	pb(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!a || !*a)
		return (false);
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
	if (ft_printf("pb\n") < 0)
		return (false);
	return (true);
}

bool	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	if (ft_printf("rb\n") < 0)
		return (false);
	return (true);
}

bool	rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (ft_printf("rrb\n") < 0)
		return (false);
	return (true);
}
