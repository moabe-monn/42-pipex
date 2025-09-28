/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:51:54 by moabe             #+#    #+#             */
/*   Updated: 2025/04/29 16:51:54 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;
	size_t		strlength;

	if (start >= ft_strlen(s))
	{
		p = ft_calloc(1, sizeof(char));
		if (!p)
			return (NULL);
		return (p);
	}
	strlength = ft_strlen(s + start);
	i = 0;
	if (len < strlength)
		strlength = len;
	p = ft_calloc(sizeof(char), strlength + 1);
	if (!p)
		return (NULL);
	while (strlength > i)
	{
		*(p + i) = *(s + start + i);
		i++;
	}
	return (p);
}