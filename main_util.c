/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:07:18 by hwakatsu          #+#    #+#             */
/*   Updated: 2025/12/26 15:14:10 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	split_free(char **tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

bool	push_stack_find_minmax(char *argv, t_stack **stack_a, int *min, int *max)
{
	int	num;

	
	push_stack(stack_a, ft_atoi(argv));

}

bool	input_num(char *argv[], t_stack **stack_a, int *min, int *max)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	i = 1;
	*min = INT_MIN;
	*max = INT_MAX;
	while (argv[i])
	{
		if (count_words(argv[i], ' ') == 1)
			push_stack(stack_a, ft_atoi(argv[i]));
		else
		{
			tmp = ft_split(argv[i], ' ');
			if (!tmp)
				return (false);
			j = 0;
			while (tmp[j])
				push_stack(stack_a, ft_atoi(tmp[j++]));
			split_free(tmp);
		}
		i++;
	}
}

void	find_min_max(t_stack *stack_a, int *min, int *max)
{
	int tmp;
	*min = stack_a->value;
	*max = stack_a->value;

}
