/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:49:30 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/15 16:15:41 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	*tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

bool	two_stack(t_stack **stack_a, int min, int max)
{
	if (min == max)
		return (false);
	if (min == (*stack_a)->value)
		return (true);
	else
	{
		ft_swap((*stack_a)->value, ((*stack_a)->next->value));
		printf("SA\n");
	}
	return (true);
}

bool	push_swap(t_stack **stack_a, int min, int max, size_t count)
{
	t_stack	*stack_b;

	if (count == 2)
		two_stack(stack_a, min, max);
	stack_b = (t_stack *)ft_calloc((count + 1), sizeof(t_stack));
}
