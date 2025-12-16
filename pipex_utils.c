/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:57:31 by moabe             #+#    #+#             */
/*   Updated: 2025/11/18 21:25:41 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void double_pointer_free(char **array)
{
	int i;

	if (array == NULL)
		return;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE); // EXIT_FAILUREは通常1に定義されている失敗を示す定数
}

void	exit_cmd_not_found(char **cmd_args)
{
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	double_pointer_free(cmd_args);
	exit(127);
}