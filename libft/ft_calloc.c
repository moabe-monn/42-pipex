/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:31:58 by moabe             #+#    #+#             */
/*   Updated: 2025/04/29 16:31:58 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	mul;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	mul = nmemb * size;
	p = malloc(mul);
	if (!p)
		return (NULL);
	ft_bzero(p, mul);
	return (p);
}

