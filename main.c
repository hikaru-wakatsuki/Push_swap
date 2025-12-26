/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 21:57:10 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/26 14:30:54 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	output_error(void)
{
	ft_printf("Error\n");
}

size_t	count_num(char *argv[])
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 1;
	while (argv[i])
		count += count_words(argv[i++], ' ');
	return (count);
}

bool	error_check(char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j])))
				return (false);
			j++;
		}
	}
}

int	main(int argc, char *argv[])
{
	size_t	count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		min;
	int		max;

	if (argc > 1)
	{
		if (!error_check(argv))
			return (output_error(), 1);
		count = count_num(argv);
		stack_a = (t_stack *)ft_calloc((count + 1), sizeof(t_stack));
		stack_b = (t_stack *)ft_calloc((count + 1), sizeof(t_stack));
		if (!stack_a || !stack_b)
			return (output_error(), 1);
		if (!input_num(argv, &stack_a))
			return (output_error(), 1);
		find_min_max();
	}
	return (output_error(), 1);
}
