/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:57:10 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/21 15:23:22 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

static void	exit_error(t_stack **a)
{
	stack_free(a);
	ft_printf("Error\n");
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
	int		min;
	int		max;

	if (argc > 1)
	{
		a = NULL;
		if (!error_check(argv))
			exit_error(&a);
		count = count_num(argv);
		if (!initialize_stack_a(argv, &a, &min, &max))
			exit_error(&a);
		if (!check_duplication(a))
			exit_error(&a);
		if (!push_swap(&a, min, max, count))
			exit_error(&a);
		stack_free(&a);
	}
	return (0);
}
