/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:19:26 by moabe             #+#    #+#             */
/*   Updated: 2025/05/23 12:54:55 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_length(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static int	count_words(char const *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*ft_strndup(char const *src, int n)
{
	int		i;
	char	*copy;

	if (src == NULL)
		return (NULL);
	copy = (char *)malloc((n + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static	void	ft_free(char **split_str, int i)
{
	while (i >= 0 && split_str[--i])
		free(split_str[i]);
	free(split_str);
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	int		i;

	i = 0;
	split_str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (split_str == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			split_str[i] = ft_strndup(s, word_length(s, c));
			if (!split_str[i])
			{
				ft_free(split_str, i);
				return (NULL);
			}
			s += word_length(s, c);
			i++;
		}
		else
			s++;
	}
	split_str[i] = NULL;
	return (split_str);
}