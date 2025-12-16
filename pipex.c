/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:15:36 by moabe             #+#    #+#             */
/*   Updated: 2025/12/16 19:50:37 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *search_path(char **envp, char *cmd)
{
    char    **paths;
    char    *full_path;
    int     i;

    if (cmd && ft_strchr(cmd, '/'))
    {
        if (access(cmd, X_OK) == 0)
            return (ft_strdup(cmd));
        return (NULL);
    }
    paths = get_paths(envp); 
    i = -1;
    while (paths && paths[++i])
    {
        full_path = join_path(paths[i], cmd);
        if (full_path && access(full_path, X_OK) == 0)
        {
            double_pointer_free(paths);
            return (full_path);
        }
        free(full_path);
    }
    double_pointer_free(paths);
    return (NULL);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmdpath;

	cmd_args = ft_split(cmd, ' ');
	if (cmd_args == NULL)
		error_exit("split error");
	cmdpath = search_path(envp, cmd_args[0]);
	if (cmdpath == NULL)
	{
		judge_file_path(cmd_args);
		exit_cmd_not_found(cmd_args);
	}
	execve(cmdpath, cmd_args, envp);
	free(cmdpath);
	double_pointer_free(cmd_args);
	error_exit("execve failed");
}

void	child_process1(char *argv[], char **envp, int	*pipe_fd)
{
	char	**cmd1;
	int		fd_in;

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
	execute_cmd(argv[2], envp);
}

void	child_process2(char *argv[], char **envp, int	*pipe_fd)
{
	char	**cmd2;
	int		fd_out;
	
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
	execute_cmd(argv[3], envp);
}

int main(int argc, char *argv[], char **envp)
{
	int 	pipe_fd[2];
	int		status;
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
	(close(pipe_fd[0]), close(pipe_fd[1]));
	(waitpid(pid1, NULL, 0), waitpid(pid2, &status, 0));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
