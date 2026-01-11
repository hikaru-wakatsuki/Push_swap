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

	if (!check_atoi(argv))
		return (false);
	num = ft_atoi(argv);				
	push_stack(stack_a, num);
	if (num < *min)
		*min = num;
	if (num > *max)
		*max = num;	
	return (true);
}

bool	input_num(char *argv[], t_stack **stack_a, int *min, int *max)
{
	char	**tmp;
	size_t	i;
	size_t	j;

	i = 1;
	*min = INT_MAX;
	*max = INT_MIN;
	while (argv[i])
	{
		if (count_words(argv[i], ' ') == 1)
		{
			if (!push_stack_find_minmax(argv[i], stack_a, min, max))
			return (false);
		}	
		else
		{
			tmp = ft_split(argv[i], ' ');
			if (!tmp)
				return (false);
			j = 0;
			while (tmp[j])
			{
				if (!push_stack_find_minmax(tmp[j], stack_a, min, max))
					return (false);
			}
			split_free(tmp);
		}
		i++;
	}
	return (true);
}
