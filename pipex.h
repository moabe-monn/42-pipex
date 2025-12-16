/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:37:09 by moabe             #+#    #+#             */
/*   Updated: 2025/12/16 16:10:06 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/uio.h>  
#include <sys/wait.h>  
#include <unistd.h>

char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char *search_path(char **envp, char *cmd);
void	child_process1(char *argv[], char **envp, int	*pipe_fd);
void	child_process2(char *argv[], char **envp, int	*pipe_fd);
void	error_exit(const char *msg);
void	double_pointer_free(char **array);
void	exit_cmd_not_found(char **cmd_args);