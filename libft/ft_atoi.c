/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 07:26:07 by moabe             #+#    #+#             */
/*   Updated: 2025/05/23 12:51:33 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static	int	long_edge(long num, int next_digit)
{
	if ((LONG_MAX / 10 < num) || (LONG_MAX / 10 == num && 7 < next_digit))
		return (-1);
	else if ((LONG_MIN / 10 > num)
		|| (LONG_MIN / 10 == num && 8 < next_digit))
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	long		num;
	int			sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign = 1 - ((*nptr++ == '-') << 1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (long_edge(num, *nptr - '0') != 1)
			return (long_edge(num * sign, *nptr - '0'));
		num = num * 10 + (*nptr++ - '0');
	}
	return (num * sign);
}