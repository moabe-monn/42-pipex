#include "pipex.h"

// int main(void)
// {
// 	pid_t	pid;
// 	extern char	**environ;
// 	char	*cmd1[3];
// 	char	*cmd2[3];
// 	int 	pipefd[2];

// 	cmd1[0] = strdup("ls");
// 	cmd1[1] = strdup("-l");
// 	cmd1[2] = NULL;

// 	cmd2[0] = strdup("wc");
// 	cmd2[1] = strdup("-l");
// 	cmd2[2] = NULL;

// 	pipe(pipefd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		dup2(pipefd[1], 1);
// 		close(pipefd[1]);
// 		close(pipefd[0]);
// 		execve("/bin/ls", cmd1, environ);
// 	}
// 	dup2(pipefd[0], 0);
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	execve("/bin/wc", cmd2, environ);
// 	return (0);
// }