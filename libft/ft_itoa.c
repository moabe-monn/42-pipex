/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:22:32 by moabe             #+#    #+#             */
/*   Updated: 2025/05/23 12:53:11 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			buf[33];
	char			*tmp;
	unsigned int	un;

	if (n < 0)
		un = -n;
	else
		un = n;
	tmp = &buf[sizeof(buf)];
	*--tmp = '\0';
	while (1)
	{
		*--tmp = "0123456789"[un % 10];
		un /= 10;
		if (!un)
			break ;
	}
	if (n < 0)
		*--tmp = '-';
	return (ft_strdup(tmp));
}