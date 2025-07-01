/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:34:49 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/05 17:05:43 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_char(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	size_calc(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (check_char(set, s1[i]) && s1[i])
		i++;
	if (j == i)
		return (0);
	j--;
	while (check_char(set, s1[j]) && j >= 0)
		j--;
	j++;
	return (j - i);
}

static void	write_tab(char *tab, char const *s1, char const *set, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (check_char(set, s1[i]) && s1[i])
		i++;
	while (j < size && s1[i + j])
	{
		tab[j] = s1[i + j];
		j++;
	}
	tab[j] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	size;

	size = size_calc(s1, set);
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (!tab)
		return (NULL);
	write_tab(tab, s1, set, size);
	return (tab);
}
