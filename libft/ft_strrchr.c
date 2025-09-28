/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:50:39 by moabe             #+#    #+#             */
/*   Updated: 2025/04/29 16:50:39 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	target;
	int				i;

	last = (char *)s;
	target = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == target)
		{
			return (last + i);
		}
		i--;
	}
	if (last[i] == target)
	{
		return (last + i);
	}
	return (NULL);
}