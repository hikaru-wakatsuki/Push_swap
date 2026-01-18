/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 12:07:18 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 19:05:05 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static bool	initialize_push(t_stack **a, int value)
{
	t_stack	*new;
	t_stack	*cur;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (false);
	new->value = value;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return (true);
	}
	cur = *a;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (true);
}

static void	split_free(char **tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

static bool	initialize_and_find_minmax(char *str, t_stack **a, int *min,
		int *max)
{
	int	num;

	if (!check_atoi(str))
		return (false);
	num = ft_atoi(str);
	if (!initialize_push(a, num))
		return (false);
	if (num < *min)
		*min = num;
	if (num > *max)
		*max = num;
	return (true);
}

static bool	split_and_initialize(char *str, t_stack **a, int *min, int *max)
{
	char	**tmp;
	size_t	i;

	tmp = ft_split(str, ' ');
	if (!tmp)
		return (false);
	i = 0;
	while (tmp[i])
	{
		if (!initialize_and_find_minmax(tmp[i++], a, min, max))
			return (false);
	}
	split_free(tmp);
	return (true);
}

bool	initialize_stack_a(char *argv[], t_stack **a, int *min, int *max)
{
	size_t	i;

	i = 1;
	*min = INT_MAX;
	*max = INT_MIN;
	while (argv[i])
	{
		if (ft_count_words(argv[i], ' ') == 1)
		{
			if (!initialize_and_find_minmax(argv[i], a, min, max))
				return (false);
		}
		else
		{
			if (!split_and_initialize(argv[i], a, min, max))
				return (false);
		}
		i++;
	}
	return (true);
}
