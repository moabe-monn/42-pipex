/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:20:24 by moabe             #+#    #+#             */
/*   Updated: 2025/05/23 12:54:05 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		*(p + i) = ch;
		i++;
	}
	return (p);
}
