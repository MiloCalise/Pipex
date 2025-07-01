/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:12:35 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/01 10:55:00 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **argv, char **envp, int *pipefd)
{
	int		infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
	{
		perror("Open");
		close(pipefd[0]);
		close(pipefd[1]);
		exit (1);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	doit(argv, envp, 2);
}

void	parent(char **argv, char **envp, int *pipefd)
{
	int		outfile_fd;

	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
	{
		perror("Open");
		close(pipefd[0]);
		close(pipefd[1]);
		wait(NULL);
		exit (1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	wait(NULL);
	doit(argv, envp, 3);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		status;
	int		exit_code;
	pid_t	pid;

	if (argc != 5)
		return (1);
	if (pipe(pipefd) == -1)
		return (perror("Pipe"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("Fork"), 1);
	if (pid == 0)
		child(argv, envp, pipefd);
	else
		parent(argv, envp, pipefd);
	exit_code = 0;
	while (wait(&status) > 0)
		exit_code = (status >> 8) & 0xFF;
	return (exit_code);
}
