/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:20:01 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/19 19:29:58 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_target
{
	size_t			a_index;
	size_t			b_index;
	size_t			ra;
	size_t			rb;
	size_t			rr;
	size_t			rra;
	size_t			rrb;
	size_t			rrr;
}					t_target;

// check_atoi.c
bool				check_atoi(const char *nptr);
// main_util.c
bool				initialize_stack_a(char *argv[], t_stack **a, int *min,
						int *max);
// push_swap_util.c
int					find_min(t_stack *a);
int					find_max(t_stack *a);
bool				initialize_pb(t_stack **a, t_stack **b, size_t *count,
						size_t *i);
// push_swap.c
bool				push_swap(t_stack **a, int min, int max, size_t count);
// stack_control_a.c
bool				sa(t_stack **a);
bool				pa(t_stack **a, t_stack **b);
bool				ra(t_stack **a);
bool				rra(t_stack **a);
// stack_control_b.c
bool				sb(t_stack **b);
bool				pb(t_stack **a, t_stack **b);
bool				rb(t_stack **b);
bool				rrb(t_stack **b);
// stack_control.c
bool				rr(t_stack **a, t_stack **b);
bool				rrr(t_stack **a, t_stack **b);
bool				bring_min_to_top(t_stack **a, t_stack **b, int min,
						size_t count);
bool				print_and_control(t_stack **a, t_stack **b, char *op);
// turk_sort_util.c
size_t				target_a_index(t_stack *a, int b_value);
bool				turk_execution(t_stack **a, t_stack **b, t_target best);
// turk_sort.c
bool				turk_sort(t_stack **a, t_stack **b, size_t a_count,
						size_t b_count);

#endif
