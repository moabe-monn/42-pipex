/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:49:44 by moabe             #+#    #+#             */
/*   Updated: 2025/04/29 16:49:44 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;
	size_t			i;

	cmp1 = (unsigned char *)buf1;
	cmp2 = (unsigned char *)buf2;
	i = 0;
	while (i < n)
	{
		if (*(cmp1 + i) != *(cmp2 + i))
		{
			return (*(cmp1 + i) - *(cmp2 + i));
		}
		i++;
	}
	return (0);
}
