/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:49:49 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/19 19:49:52 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

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

bool	bring_min_to_top(t_stack **a, t_stack **b, int min, size_t count)
{
	size_t	i;
	t_stack	*cur;
	char	*op;

	if (!a || !*a)
		return (false);
	i = 0;
	cur = *a;
	while (cur && cur->value != min)
	{
		cur = cur->next;
		i++;
	}
	if (i <= count / 2)
		op = "ra";
	else
		op = "rra";
	while ((*a)->value != min)
	{
		if (!print_and_control(a, b, op))
			return (false);
	}
	return (true);
}

bool	stack_control(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		return (sa(a));
	if (ft_strcmp(op, "sb") == 0)
		return (sb(b));
	if (ft_strcmp(op, "pa") == 0)
		return (pa(a, b));
	if (ft_strcmp(op, "pb") == 0)
		return (pb(a, b));
	if (ft_strcmp(op, "ra") == 0)
		return (ra(a));
	if (ft_strcmp(op, "rb") == 0)
		return (rb(b));
	if (ft_strcmp(op, "rr") == 0)
		return (rr(a, b));
	if (ft_strcmp(op, "rra") == 0)
		return (rra(a));
	if (ft_strcmp(op, "rrb") == 0)
		return (rrb(b));
	if (ft_strcmp(op, "rrr") == 0)
		return (rrr(a, b));
	return (false);
}

bool	print_and_control(t_stack **a, t_stack **b, char *op)
{
	if (!stack_control(a, b, op))
		return (false);
	if (ft_printf("%s\n", op) < 0)
		return (false);
	return (true);
}
