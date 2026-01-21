/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:43:29 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/21 20:43:06 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	check_atoi(const char *nptr)
{
	long	sign;
	long	nbr;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*(nptr++) == '-')
			sign = -1;
	}
	if (!ft_isdigit(*nptr))
		return (false);
	nbr = 0;
	while (ft_isdigit(*nptr))
	{
		nbr *= 10;
		nbr += (long)(*(nptr++) - '0');
	}
	if (*nptr != '\0' && !(ft_isspace(*nptr)))
		return (false);
	nbr = nbr * sign;
	if (nbr < INT_MIN || INT_MAX < nbr)
		return (false);
	return (true);
}

void	stack_free(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

bool	is_sorted(t_stack *a)
{
	if (!a)
		return (true);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}
