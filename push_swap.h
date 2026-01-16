/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:20:01 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/16 15:49:25 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// check_atoi.c
bool				check_atoi(const char *nptr);
// main_util.c
bool				initialize_stack_a(char *argv[], t_stack **a, int *min,
						int *max);
// push_swap.c
bool				push_swap(t_stack **a, int min, int max, size_t count);
// stack_control_a.c
bool				pa(t_stack **a, t_stack **b);
bool				ra(t_stack **a);
bool				rra(t_stack **a);
// stack_control_b.c
bool				pb(t_stack **a, t_stack **b);
bool				rb(t_stack **b);
bool				rrb(t_stack **b);
// stack_control.c
void				bring_min_to_top(t_stack **a, int min, size_t count);

#endif
