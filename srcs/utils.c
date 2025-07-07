/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:02:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/01 12:43:29 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strrchrr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	if (ft_strlen(str) == 0)
		i = 0;
	else
		i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c && str[i + 1])
			return (1);
		i--;
	}
	return (0);
}

char	*final_path(char **argv, char **envp, int j)
{
	char	*correct;
	char	**temp;

	if (!ft_strrchrr(argv[j], 47))
	{
		correct = correct_path(argv, envp, j);
		if (!correct)
			return (NULL);
	}
	else
	{
		temp = ft_split(argv[j], ' ');
		if (!temp)
			return (NULL);
		if (access(temp[0], X_OK) != 0)
		{
			perror("Access");
			return (free_split(temp), NULL);
		}
		correct = ft_strdup(temp[0]);
		free_split(temp);
	}
	return (correct);
}

void	doit(char **argv, char **envp, int j)
{
	char	**cmd;
	char	*path;

	path = final_path(argv, envp, j);
	if (!path)
		exit(127);
	cmd = ft_split(argv[j], ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free_split(cmd);
		free(path);
		ft_putstr_fd("Invalid command", 2);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("Execve");
		free(path);
		free_split(cmd);
		exit (1);
	}
}

char	**get_args(char **argv, int i)
{
	char	**args;

	args = ft_split(argv[i], ' ');
	if (!args)
		return (NULL);
	return (args);
}
