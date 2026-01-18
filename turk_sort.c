/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:42:35 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 19:10:08 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static t_target	initialize_turk(t_target cur)
{
	cur.ra = 0;
	cur.rb = 0;
	cur.rr = 0;
	cur.rra = 0;
	cur.rrb = 0;
	cur.rrr = 0;
	return (cur);
}

static t_target	r_cal(t_target cur)
{
	if (cur.a_index >= cur.b_index)
	{
		cur.rr = cur.b_index;
		cur.ra = cur.a_index - cur.b_index;
		return (cur);
	}
	else
	{
		cur.rr = cur.a_index;
		cur.rb = cur.b_index - cur.a_index;
		return (cur);
	}
}

static t_target	rr_cal(t_target cur, size_t a_count, size_t b_count)
{
	if ((a_count - cur.a_index) >= (b_count - cur.b_index))
	{
		cur.rrr = (b_count - cur.b_index);
		cur.rra = (a_count - cur.a_index) - (b_count - cur.b_index);
		return (cur);
	}
	else
	{
		cur.rrr = (a_count - cur.a_index);
		cur.rrb = (b_count - cur.b_index) - (a_count - cur.a_index);
		return (cur);
	}
}

static t_target	turk_cal(t_target cur, size_t a_count, size_t b_count)
{
	cur = initialize_turk(cur);
	if (cur.a_index <= a_count / 2 && cur.b_index <= b_count / 2)
		return (r_cal(cur));
	if (cur.a_index >= a_count / 2 && cur.b_index >= b_count / 2)
		return (rr_cal(cur, a_count, b_count));
	if (cur.a_index <= a_count / 2)
		cur.ra = cur.a_index;
	else
		cur.rra = (a_count - cur.a_index);
	if (cur.b_index <= b_count / 2)
		cur.rb = cur.b_index;
	else
		cur.rrb = (b_count - cur.b_index);
	return (cur);
}

bool	turk_sort(t_stack **a, t_stack **b, size_t a_count, size_t b_count)
{
	t_target	best;
	size_t		best_cost;
	t_target	cur;
	size_t		cur_cost;
	t_stack		*tmp;

	best_cost = SIZE_MAX;
	cur.b_index = 0;
	tmp = *b;
	while (tmp)
	{
		cur.a_index = target_a_index(*a, tmp->value);
		cur = turk_cal(cur, a_count, b_count);
		cur_cost = cur.ra + cur.rb + cur.rr + cur.rra + cur.rrb + cur.rrr;
		if (best_cost > cur_cost)
		{
			best = cur;
			best_cost = cur_cost;
		}
		tmp = tmp->next;
		cur.b_index++;
	}
	if (!turk_execution(a, b, best))
		return (false);
	return (true);
}
