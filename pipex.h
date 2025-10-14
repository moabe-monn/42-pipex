/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:37:09 by moabe             #+#    #+#             */
/*   Updated: 2025/09/30 20:50:16 by moabe            ###   ########.fr       */
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

typedef struct s_cpt
{
	char	**argv;
	char	**envp;
	int		cmdn;
}			t_cpt;

char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*search_path(char **envp, char *cmd);
void	make_pipes(int i, t_cpt	*cpt);
void	child_process_first(t_cpt	*cpt);
void	child_process_last(t_cpt	*cpt);
void	child_process(int i, t_cpt	*cpt);
void	error_exit(const char *msg);
void	double_pointer_free(char **array);