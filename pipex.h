/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:37:09 by moabe             #+#    #+#             */
/*   Updated: 2025/12/16 18:33:35 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/uio.h>  
#include <sys/wait.h>  
#include <unistd.h>
#include <errno.h>
#include "libft/libft.h"

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char *search_path(char **envp, char *cmd);
void	child_process1(char *argv[], char **envp, int	*pipe_fd);
void	child_process2(char *argv[], char **envp, int	*pipe_fd);
void	error_exit(const char *msg);
void	double_pointer_free(char **array);
void	exit_cmd_not_found(char **cmd_args);
void	judge_file_path(char **cmd_args);
void	execute_cmd(char *cmd, char **envp);
char *make_path(char	**paths, char	*path_part, char *cmd);

#endif