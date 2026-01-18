/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:48:41 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 12:03:32 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!b || !*b)
		return (false);
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
	if (ft_printf("pa\n") < 0)
		return (false);
	return (true);
}

bool	ra(t_stack **a)
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
	if (ft_printf("ra\n") < 0)
		return (false);
	return (true);
}

bool	rra(t_stack **a)
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
	if (ft_printf("rra\n") < 0)
		return (false);
	return (true);
}
