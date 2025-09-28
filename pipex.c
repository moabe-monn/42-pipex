/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:15:36 by moabe             #+#    #+#             */
/*   Updated: 2025/09/28 00:15:08 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *search_path(char **envp, char *cmd)
{
	//execve用のシステムコールのパスを探す関数
	char	**paths;
	char	*path_part;
	char	*full_path;
	int		i;

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

void	child_process1(char *argv[], char **envp, int	*pipe_fd)
{
	char	**cmd1;
	char 	*cmdpath1;
	pid_t	fd_in;
	
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1) 
    	error_exit(argv[1]);
	cmd1 = ft_split(argv[2], ' ');
	if (cmd1 == NULL)
		error_exit("split error");
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd_in);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmdpath1 = search_path(envp, cmd1[0]);
	if (cmdpath1 == NULL)
		error_exit("command not found");
	execve(cmdpath1, cmd1, envp);
    error_exit("execve failed"); 
}

void	child_process2(char *argv[], char **envp, int	*pipe_fd)
{
	char	**cmd2;
	char 	*cmdpath2;
	pid_t	fd_out;
	
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); //所有者+グループ+そのほか
	if (fd_out == -1)
		error_exit(argv[4]);
	cmd2 = ft_split(argv[3], ' ');
	if (cmd2 == NULL)
		error_exit("split error");
	dup2(fd_out, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(fd_out);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmdpath2 = search_path(envp, cmd2[0]);
	if (cmdpath2 == NULL)
		error_exit("command not found");
	execve(cmdpath2, cmd2, envp);
    error_exit("execve failed"); 
}

int main(int argc, char *argv[], char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (1);
	if (pipe(pipe_fd) == -1)
		error_exit("pipe");	
	pid1 = fork();
	if (pid1 == -1)
		error_exit("fork");
	else if (pid1 == 0)
		child_process1(argv, envp, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("fork");
	else if (pid2 == 0)
		child_process2(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

