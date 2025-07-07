/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:53:51 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/03 16:00:18 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	doc(int argc, char **argv, char **envp, int *oldfd)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc != 6)
	{
		ft_putstr_fd("Missing arguments\n", 2);
		exit(1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("Pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork");
		exit(1);
	}
	if (pid == 0)
		here_first(argv, pipefd, oldfd);
	close(pipefd[1]);
	*oldfd = pipefd[0];
	waitpid(pid, NULL, 0);
	mid(argv, envp, oldfd, 3);
}

void	here_first(char **argv, int *pipefd, int *oldfd)
{
	char	*line;

	close(pipefd[0]);
	write(STDOUT_FILENO, "heredoc> ", 9);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& line[ft_strlen(argv[2])] == '\n')
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, ft_strlen(line));
		free(line);
		write(STDOUT_FILENO, "heredoc> ", 9);
	}
	close(pipefd[1]);
	*oldfd = pipefd[0];
	exit(1);
}

void	here_last(char **argv, char **envp, int oldfd)
{
	int		outfile_fd;
	int		pipefd[2];
	pid_t	pid;

	get_pipe(pipefd, &pid);
	if (pid == 0)
	{
		close(pipefd[0]);
		outfile_fd = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (outfile_fd == -1)
		{
			perror("Open");
			close (pipefd[1]);
			exit(1);
		}
		dup2(oldfd, STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(pipefd[1]);
		close(outfile_fd);
		doit(argv, envp, 4);
	}
	close (oldfd);
}
