/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:49:30 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/16 15:59:17 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

bool	two_stack(t_stack **a, int min, int max)
{
	if (min == (*a)->value)
		return (true);
	else
	{
		ft_swap((*a)->value, ((*a)->next->value));
		if (ft_printf("sa\n") < 0)
			return (false);
	}
	return (true);
}

bool	three_stack(t_stack **a, int min, int max)
{
	if ((*a)->value == max)
	{
		if (!ra(a))
			return (false);
		if (!two_stack(a, min, max))
			return (false);
	}
	else if ((*a)->next->value == max)
	{
		if (!rra(a))
			return (false);
		if (!two_stack(a, min, max))
			return (false);
	}
	else
	{
		if (!two_stack(a, min, max))
			return (false);
	}
	return (true);
}

bool	under_five_stack(t_stack **a, int min, int max, size_t count)
{
	t_stack	*stack_b;

	bring_min_to_top(a, min, count);
}

bool	push_swap(t_stack **a, int min, int max, size_t count)
{
	if (count == 2)
	{
		if (!two_stack(a, min, max))
			return (false);
	}
	if (count == 3)
	{
		if (!three_stack(a, min, max))
			return (false);
	}
	if (count <= 5)
	{
		if (!under_five_stack(a, min, max, count))
			return (false);
	}
}
