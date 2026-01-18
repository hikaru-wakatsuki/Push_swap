/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwakatsu <hwakatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:43:29 by hwakatsu          #+#    #+#             */
/*   Updated: 2026/01/18 18:52:14 by hwakatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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
