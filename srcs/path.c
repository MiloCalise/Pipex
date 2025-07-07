/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:07:31 by miltavar          #+#    #+#             */
/*   Updated: 2025/07/01 12:09:53 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*path_len(char *s)
{
	int		i;
	int		j;
	char	*full_path;

	i = 5;
	while (s[i] && s[i] != '\n')
		i++;
	j = i - 5;
	full_path = ft_calloc(j + 2, 1);
	if (!full_path)
		return (NULL);
	i = 5;
	j = 0;
	while (s[i] && s[i] != '\n')
	{
		full_path[j] = s[i];
		i++;
		j++;
	}
	full_path[j] = '\0';
	return (full_path);
}

char	**get_path(char **envp)
{
	int		i;
	char	**paths;
	char	*temp;

	i = 0;
	paths = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			temp = path_len(envp[i]);
			if (!temp)
				return (NULL);
			paths = ft_split(temp, ':');
			free(temp);
			if (!paths)
				return (NULL);
			break ;
		}
		i++;
	}
	if (!paths)
		return (NULL);
	return (paths);
}

char	*build_and_check(char **paths, char **cmd)
{
	char	*correct;
	int		i;

	if (!paths || !cmd || !cmd[0])
		return (NULL);
	i = 0;
	while (paths[i])
	{
		correct = ft_strjoin(paths[i], cmd[0]);
		if (!correct)
			return (NULL);
		if (access(correct, X_OK) == 0)
			return (correct);
		free(correct);
		i++;
	}
	return (ft_putstr_fd("Command not found", 2), NULL);
}

char	*correct_path(char **argv, char **envp, int j)
{
	char	**paths;
	char	**cmd;
	char	*correct;
	char	*temp;

	paths = get_path(envp);
	if (!paths)
		return (NULL);
	cmd = ft_split(argv[j], ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free_split(cmd);
		ft_putstr_fd("Invalid command", 2);
		return (free_split(paths), NULL);
	}
	temp = cmd[0];
	cmd[0] = ft_strjoin("/", cmd[0]);
	free(temp);
	if (!cmd[0])
		return (free_split(paths), free_split(cmd), NULL);
	correct = build_and_check(paths, cmd);
	if (!correct)
		return (free_split(paths), free_split(cmd), NULL);
	return (free_split(paths), free_split(cmd), correct);
}

void	free_split(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
}
