/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_over_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:42:35 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/16 15:53:16 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	find_max(t_stack *a)
{
	int	max;

	max = INT_MIN;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

bool	turk_sort(t_stack *a, t_stack *b, size_t a_count, size_t b_count)
{
	while (b)
	{
		if ;
		b = b->next;
	}
}

bool	turk_sort(t_stack **a, t_stack **b, size_t a_count, size_t b_count)
{

}

bool	over_five_stack(t_stack **a, int min, int max, size_t count)
{
	t_stack	*b;
	size_t	i;

	b = NULL;
	i = 0;
	while (i < count - 3)
	{
		pb(a, &b);
		i++;
	}
	if (!three_stack(a, find_min(*a), find_max(*a)))
		return (false);
	while (i > 0)
	{
		if (!turk_sort(a, &b, count - i, i))
			return (false);
	}
	return (true);
}
