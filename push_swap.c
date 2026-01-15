/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:49:30 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/15 19:04:18 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

bool	two_stack(t_stack **stack_a, int min, int max)
{
	if (min == max)
		return (false);
	if (min == (*stack_a)->value)
		return (true);
	else
	{
		ft_swap((*stack_a)->value, ((*stack_a)->next->value));
		if (ft_printf("SA\n") < 0)
			return (false);
	}
	return (true);
}

bool	three_stack(t_stack **stack_a, int min, int max)
{
	if (min == max)
		return (false);
	if ((*stack_a)->value == max)
	{
		if (ft_printf("SA\n") < 0)
			return (false);
		ft_swap((*stack_a)->value, ((*stack_a)->next->value));
	}

}

bool	push_swap(t_stack **stack_a, int min, int max, size_t count)
{
	t_stack	*stack_b;

	if (count == 2)
	{
		if (!two_stack(stack_a, min, max))
			return (false);
	}
	if (count == 3)
	{
		if (!three_stack(stack_a, min, max))
			return (false);
	}
	stack_b = (t_stack *)ft_calloc((count + 1), sizeof(t_stack));
}
