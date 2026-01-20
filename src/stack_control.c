/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:49:49 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/20 13:20:41 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return (false);
	if (!b || !*b || !(*b)->next)
		return (false);
	sa(a);
	sb(b);
	return (true);
}

bool	rr(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return (false);
	if (!b || !*b || !(*b)->next)
		return (false);
	ra(a);
	rb(b);
	return (true);
}

bool	rrr(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return (false);
	if (!b || !*b || !(*b)->next)
		return (false);
	rra(a);
	rrb(b);
	return (true);
}

bool	stack_control(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		return (sa(a));
	if (ft_strcmp(op, "sb\n") == 0)
		return (sb(b));
	if (ft_strcmp(op, "ss\n") == 0)
		return (ss(a, b));
	if (ft_strcmp(op, "pa\n") == 0)
		return (pa(a, b));
	if (ft_strcmp(op, "pb\n") == 0)
		return (pb(a, b));
	if (ft_strcmp(op, "ra\n") == 0)
		return (ra(a));
	if (ft_strcmp(op, "rb\n") == 0)
		return (rb(b));
	if (ft_strcmp(op, "rr\n") == 0)
		return (rr(a, b));
	if (ft_strcmp(op, "rra\n") == 0)
		return (rra(a));
	if (ft_strcmp(op, "rrb\n") == 0)
		return (rrb(b));
	if (ft_strcmp(op, "rrr\n") == 0)
		return (rrr(a, b));
	return (false);
}

bool	print_and_control(t_stack **a, t_stack **b, char *op)
{
	if (!stack_control(a, b, op))
		return (false);
	if (ft_printf("%s", op) < 0)
		return (false);
	return (true);
}
