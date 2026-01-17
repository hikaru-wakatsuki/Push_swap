/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:57:10 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/17 16:50:30 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	output_error(void)
{
	ft_printf("Error\n");
}

static size_t	count_num(char *argv[])
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 1;
	while (argv[i])
		count += count_words(argv[i++], ' ');
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
				|| argv[i][j] == '+' || argv[i][j] == '-'))
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
		if (!error_check(argv))
			return (output_error(), 1);
		count = count_num(argv);
		a = (t_stack *)ft_calloc((count + 1), sizeof(t_stack));
		if (!a)
			return (output_error(), 1);
		if (!initialize_stack_a(argv, &a, &min, &max))
			return (output_error(), 1);
		if (!check_duplication(a))
			return (output_error(), 1);
		if (!push_swap(&a, min, max, count))
			return (output_error(), 1);
	}
	return (0);
}
