/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:48:41 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/15 19:05:36 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	push_stack(t_stack **stack, int push_value)
{
	t_stack	**cur;

	if (!stack || !*stack)
		return ;
	cur = stack;
	(*stack)->value = push_value;
	(*stack)->next = *cur;
}

bool	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;


	if (!stack || !*stack)
		return (false);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	
	return (true);
}
