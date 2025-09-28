/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:53:07 by moabe             #+#    #+#             */
/*   Updated: 2025/05/23 12:53:45 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d_cpy;
	const unsigned char	*s_cpy;

	d_cpy = (unsigned char *)dest;
	s_cpy = (const unsigned char *)src;
	while (n--)
	{
		*d_cpy++ = *s_cpy++;
	}
	return (dest);
}
