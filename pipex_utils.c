/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:57:31 by moabe             #+#    #+#             */
/*   Updated: 2025/09/27 16:21:20 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void double_pointer_free(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void  error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE); // EXIT_FAILUREは通常1に定義されている失敗を示す定数
}