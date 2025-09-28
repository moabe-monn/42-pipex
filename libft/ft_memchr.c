/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:49:55 by moabe             #+#    #+#             */
/*   Updated: 2025/04/29 16:49:55 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	const char	*p;
	size_t		i;

	p = (const char *)buf;
	i = 0;
	while (i < n)
	{
		if (*(p + i) == (char)ch)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}
