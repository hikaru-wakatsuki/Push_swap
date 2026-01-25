/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:43:01 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/23 19:01:36 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../includes/push_swap.h"
#include "../libft/libft.h"

bool	input_and_control(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!line)
			return (true);
		if (!stack_control(a, b, line))
		{
			free(line);
			return (false);
		}
		free(line);
		line = NULL;
	}
	return (false);
}

bool	checker(t_stack **a, t_stack **b, size_t count)
{
	size_t	i;
	t_stack	*cur;

	i = 1;
	if (!*a)
		return (ft_printf("KO\n") >= 0);
	cur = *a;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (ft_printf("KO\n") >= 0);
		cur = cur->next;
		i++;
	}
	if (count != i || *b != NULL)
		return (ft_printf("KO\n") >= 0);
	return (ft_printf("OK\n") >= 0);
}
