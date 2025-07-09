/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:05:13 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/09 09:54:13 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_pipe(int *pipefd, pid_t *pid)
{
	if (pipe(pipefd) == -1)
	{
		perror("Pipe");
		exit(1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		perror("Fork");
		exit(1);
	}
}

void	first(char **argv, char **envp, int *oldfd)
{
	int		infile_fd;
	int		pipefd[2];
	pid_t	pid;

	get_pipe(pipefd, &pid);
	if (pid == 0)
	{
		close(pipefd[0]);
		infile_fd = open(argv[1], O_RDONLY);
		if (infile_fd == -1)
		{
			perror(argv[1]);
			close(pipefd[0]);
			close(pipefd[1]);
			exit(1);
		}
		dup2(infile_fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(infile_fd);
		close(pipefd[1]);
		doit(argv, envp, 2);
	}
	close(pipefd[1]);
	*oldfd = pipefd[0];
}

void	mid(char **argv, char **envp, int *oldfd, int j)
{
	int		prevfd;
	int		pipefd[2];
	pid_t	pid;

	prevfd = *oldfd;
	get_pipe(pipefd, &pid);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(prevfd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(prevfd);
		close(pipefd[1]);
		doit(argv, envp, j);
	}
	close(prevfd);
	close(pipefd[1]);
	*oldfd = pipefd[0];
}

void	last(int argc, char **argv, char **envp, int oldfd)
{
	int		outfile_fd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
	{
		outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
		{
			perror(argv[argc - 1]);
			exit(1);
		}
		dup2(oldfd, STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(oldfd);
		close(outfile_fd);
		doit(argv, envp, argc - 2);
	}
	close(oldfd);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	oldfd;
	int	status;
	int	exit_code;

	if (argc < 5)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		first(argv, envp, &oldfd);
		i = 3;
		while (i < argc - 2)
			mid(argv, envp, &oldfd, i++);
		last(argc, argv, envp, oldfd);
	}
	else
	{
		doc(argc, argv, envp, &oldfd);
		here_last(argv, envp, oldfd);
	}
	exit_code = 0;
	while (wait(&status) > 0)
		exit_code = (status >> 8) & 0xFF;
	return (exit_code);
}
