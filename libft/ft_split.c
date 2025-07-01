/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:17:40 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/05 17:05:05 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_tab(char const *s, char c)
{
	size_t	i;
	size_t	strs;

	i = 0;
	strs = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
			}
			strs++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (strs);
}

static size_t	calc_str(char const *s, char c, size_t i, size_t word)
{
	size_t	j;
	size_t	count;

	j = 0;
	word = 0;
	count = 0;
	while (s[j] == c)
		j++;
	while (s[j] && word <= i)
	{
		if (s[j] != c)
		{
			if (word == i)
				while (s[j] && s[j] != c && ++count)
					j++;
			else
				while (s[j] && s[j] != c)
					j++;
			word++;
		}
		else
			j++;
	}
	return (count);
}

static char	*copy_word(char *tab, const char *s, size_t j, char c)
{
	size_t	k;

	k = 0;
	while (s[j] && s[j] != c)
	{
		tab[k] = s[j];
		k++;
		j++;
	}
	tab[k] = '\0';
	return (tab);
}

static char	*write_tab(const char *s, char c, size_t i, char *tab)
{
	size_t	j;
	size_t	word;

	j = 0;
	word = 0;
	tab = (char *)malloc(sizeof(char) * (calc_str(s, c, i, word) + 1));
	if (!tab)
		return (NULL);
	while (s[j] == c)
		j++;
	while (s[j])
	{
		if (s[j] != c)
		{
			if (word == i)
				tab = copy_word(tab, s, j, c);
			while (s[j] && s[j] != c)
				j++;
			word++;
		}
		else
			j++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (calc_tab(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < calc_tab(s, c))
	{
		tab[i] = write_tab(s, c, i, tab[i]);
		if (!tab[i])
		{
			while (i > 0)
				free(tab[--i]);
			return (free(tab), NULL);
		}
		i++;
	}
	return (tab[i] = NULL, tab);
}
