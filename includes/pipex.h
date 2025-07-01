/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:16:22 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/01 09:50:31 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

void	free_split(char **strs);
void	f(char *p1, char *p2, char **a1, char **a2);
void	child(char **argv, char **envp, int *pipefd);
void	parent(char **argv, char **envp, int *pipefd);
void	doit(char **argv, char **envp, int j);

int		ft_strrchrr(const char *s, int c);

char	*final_path(char **argv, char **envp, int j);
char	*correct_path(char **argv, char **envp, int j);
char	*path_len(char *s);
char	*build_and_check(char **paths, char **cmd);

char	**get_args(char **argv, int i);
char	**get_path(char **envp);

#endif
