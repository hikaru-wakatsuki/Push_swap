/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:44:35 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/19 21:29:44 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../includes/push_swap.h"
# include "../libft/libft.h"

bool	input_and_control(t_stack **a, t_stack **b, size_t count);
bool	checker(t_stack *a, t_stack *b, size_t count);

#endif
