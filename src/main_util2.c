/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:43:29 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/19 21:33:42 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

bool	check_atoi(const char *nptr)
{
	long	sign;
	long	nbr;

	while ((9 <= *nptr && *nptr <= 13) || (*nptr == ' '))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nbr = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		nbr *= 10;
		nbr += (long)(*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0' && !('0' <= *nptr && *nptr <= '9'))
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
