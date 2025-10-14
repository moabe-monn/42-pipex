/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:15:36 by moabe             #+#    #+#             */
/*   Updated: 2025/09/30 20:52:06 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_first(t_cpt	*cpt)
{
	char	**cmd1;
	char	*cmdpath;
	int		fd_in;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	fd_in = open(cpt->argv[0], O_RDONLY);
	if (fd_in == -1)
		error_exit(cpt->argv[0]);
	cmd1 = ft_split(cpt->argv[1], ' ');
	if (cmd1 == NULL)
		error_exit("split error");
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(fd_in);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmdpath = search_path(cpt->envp, cmd1[0]);
	if (cmdpath == NULL)
		error_exit("command not found");
	execve(cmdpath, cmd1, cpt->envp);
	double_pointer_free(cmd1);
	error_exit("execve failed");
}

void	child_process_last(t_cpt	*cpt)
{
	char	**cmd;
	char	*cmdpath;
	int		fd_out;
	pid_t	ret;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	fd_out = open(cpt->argv[cpt->cmdn], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		error_exit(cpt->argv[1]);
	cmd = ft_split(cpt->argv[0], ' ');
	if (cmd == NULL)
		error_exit("split error");
	ret = fork();
	if (ret == -1)
		error_exit("fork");
	if (ret == 0)
	{
		close(pipe_fd[0]);
		dup2(fd_out, STDOUT_FILENO);
		close(pipe_fd[1]);
		make_pipes(cpt->cmdn - 2, cpt);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		cmdpath = search_path(cpt->envp, cmd[0]);
		if (cmdpath == NULL)
			error_exit("command not found");
		execve(cmdpath, cmd, cpt->envp);
		double_pointer_free(cmd);
		error_exit("execve failed");
	}
}

void	child_process(int i, t_cpt	*cpt)
{
	pid_t	ret;
	char	*cmdpath;
	char	**cmd;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	ret = fork();
	if (ret == -1)
		error_exit("fork");
	cmd = ft_split(cpt->argv[i + 1], ' ');
	if (cmd == NULL)
		error_exit("split error");
	if (ret == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		make_pipes(i - 1, cpt);
	}
	else
	{
		cmdpath = search_path(cpt->envp, cpt->argv[i + 1]);
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		execve(cmdpath, cmd, cpt->envp);
		double_pointer_free(cmd);
		error_exit("execve failed");
	}
}

void	make_pipes(int i, t_cpt	*cpt)
{
	if (i == cpt->cmdn - 1)
		child_process_last(cpt);
	else if (i == 0)
		child_process_first(cpt);
	else
		child_process(i, cpt);
}

int	main(int argc, char *argv[], char **envp)
{
	pid_t	ret;
	t_cpt	*cpt;

	cpt = (t_cpt *)malloc(sizeof(t_cpt));
	if (argc < 5)
		return (1);
	cpt->cmdn = argc - 3;
	cpt->argv = ++argv;
	cpt->envp = envp;
	ret = fork();
	if (ret == -1)
		error_exit("fork");
	else if (ret == 0)
		make_pipes(cpt->cmdn - 1, cpt);
	else
		waitpid(ret, NULL, 0);
	return (0);
}


//dup2の際にnewfdが開いていれば勝手に閉じられます。これに失敗する可能性があり、その場合エラー情報は握りつぶされます。
//なので、stdinとstdoutも明示的に閉じてエラー処理をした方が良いとされます。

// int	main(int argc, char *argv[], char **envp)
// {
// 	int		pipe_fd[2];
// 	pid_t	pid1;
// 	pid_t	pid2;

// 	if (argc != 5)
// 		return (1);
// 	if (pipe(pipe_fd) == -1)
// 		error_exit("pipe");
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		error_exit("fork");
// 	else if (pid1 == 0)
// 		child_process1(argv, envp, pipe_fd);
// 	pid2 = fork();
// 	if (pid2 == -1)
// 		error_exit("fork");
// 	else if (pid2 == 0)
// 		child_process2(argv, envp, pipe_fd);
// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }
