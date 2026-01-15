/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_control2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:49:49 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/15 22:11:50 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	bring_min_to_top(t_stack **a, int min, size_t count)
{
	size_t	i;
	t_stack	*pos;

	i = 0;
	pos = *a;
	while (pos->value != min)
	{
		pos = pos->next;
		i++;
	}
	if (i <= count / 2)
	{
		while ((*a)->value != min)
			rotate(a);
	}
	else
	{
		while ((*a)->value != min)
			reverse_rotate(a);
	}
}
