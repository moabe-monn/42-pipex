/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:45:40 by moabe             #+#    #+#             */
/*   Updated: 2025/12/16 19:45:42 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
char **get_paths(char **envp)
{
    if (envp == NULL)
        return (NULL);
    while (*envp != NULL && ft_strncmp(*envp, "PATH=", 5) != 0)
        envp++;
    if (*envp == NULL)
        return (NULL);
    return (ft_split(*envp + 5, ':'));
}