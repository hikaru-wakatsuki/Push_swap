/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:20:01 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/15 16:31:22 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// main_util.c
bool				initialize_stack_a(char *argv[], t_stack **stack_a,
						int *min, int *max);
void				find_min_max(t_stack *stack_a, int *min, int *max);
// push_swap.c
bool				push_swap(t_stack **stack_a, int min, int max,
						size_t count);
// stack_control.c
void				push_stack(t_stack **stack, int push_value);

bool				check_atoi(const char *nptr);

#endif
