/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:20:01 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/15 22:14:59 by hwakatsu         ###   ########.fr       */
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
bool	pa(t_stack **stack_a, t_stack **stack_b);
bool	ra(t_stack **stack);
bool	rra(t_stack **stack);
void				bring_min_to_top(t_stack **stack_a, int min, size_t count);
#endif
