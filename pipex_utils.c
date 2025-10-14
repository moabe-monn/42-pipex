/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:57:31 by moabe             #+#    #+#             */
/*   Updated: 2025/09/30 17:37:28 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	double_pointer_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void 	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE); // EXIT_FAILUREは通常1に定義されている失敗を示す定数
}

char	*search_path(char **envp, char *cmd)
{
	char	**paths;
	char	*path_part;
	char	*full_path;
	int		i;

	// execve用のシステムコールのパスを探す関数
	while (*envp != NULL && strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp == NULL)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path_part = ft_strjoin(paths[i], "/");
		if (path_part == NULL)
		{
			double_pointer_free(paths);
			return (NULL);
		}
		full_path = ft_strjoin(path_part, cmd);
		if (access(full_path, X_OK) == 0)
		{
			double_pointer_free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	double_pointer_free(paths);
	return (NULL);
}