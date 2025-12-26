/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:48:41 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/26 11:58:02 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	push_stack(t_stack **stack, int push_value)
{
	t_stack	**cur;

	cur = stack;
	(*stack)->value = push_value;
	(*stack)->next = *cur;
}

void	pop_stack(t_stack **stack)
{
}
