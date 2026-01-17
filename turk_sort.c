/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:42:35 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/17 16:40:36 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

size_t	search_index_a(t_stack *a, int b_value)
{
	size_t	a_index;

	a_index = 0;
	while (a)
	{
		if (a->value > b_value)
			return (a_index);
		a_index++;
		a = a->next;
	}
	return (a_index);
}

size_t	calcuration_cost(size_t a_index, size_t b_index, size_t a_count,
		size_t b_count)
{
	size_t	a_calcuration;
	size_t	b_calcuration;

	if (a_index == a_count)
		a_index = 0;
	if (a_index <= a_count / 2)
		a_calcuration = a_index;
	else
		a_calcuration = a_count - a_index;
	if (b_index <= b_count / 2)
		b_calcuration = b_index;
	else
		b_calcuration = b_count - b_index;
	if ((a_index <= a_count / 2 && b_index <= b_count / 2)
		|| (a_index >= a_count / 2 && b_index >= b_count / 2))
	{
		if (a_calcuration >= b_calcuration)
			return (a_calcuration - b_calcuration);
		else
			return (b_calcuration - a_calcuration);
	}
	else
		return (a_calcuration + b_calcuration);
}

bool	turk_sort(t_stack *a, t_stack *b, size_t a_count, size_t b_count)
{
	size_t	cost;
	size_t	b_index;

	b_index = 0;
	while (b)
	{
		b = b->next;
		b_index++;
	}
}
