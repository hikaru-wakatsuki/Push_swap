/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:12:56 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/23 19:00:07 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	exit_error(t_stack **a, t_stack **b)
{
	stack_free(a);
	stack_free(b);
	write(2, "Error\n", 6);
	exit(1);
}

static size_t	count_num(char *argv[])
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 1;
	while (argv[i])
		count += ft_count_words(argv[i++], ' ');
	return (count);
}

static bool	error_check(char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j])
					|| argv[i][j] == '-'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_duplication(t_stack *stack)
{
	t_stack	*cur;

	while (stack)
	{
		cur = stack->next;
		while (cur)
		{
			if (cur->value == stack->value)
				return (false);
			cur = cur->next;
		}
		stack = stack->next;
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	size_t	count;
	t_stack	*a;
	t_stack	*b;
	int		min;
	int		max;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		if (!error_check(argv))
			exit_error(&a, &b);
		count = count_num(argv);
		if (!initialize_stack_a(argv, &a, &min, &max))
			exit_error(&a, &b);
		if (!check_duplication(a))
			exit_error(&a, &b);
		if (!input_and_control(&a, &b))
			exit_error(&a, &b);
		if (!checker(&a, &b, count))
			exit_error(&a, &b);
		stack_free(&a);
		stack_free(&b);
	}
	return (0);
}
