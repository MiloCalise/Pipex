/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:52:11 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/05 17:05:51 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_str(char const *s, char *dup, size_t i)
{
	size_t	j;

	j = 0;
	while (s[j] && j < i)
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
	{
		dup = (char *)malloc(sizeof(char));
		if (!dup)
			return (NULL);
		dup[0] = '\0';
		return (dup);
	}
	i = ft_strlen(s + start);
	if (i > len)
		i = len;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	write_str(s + start, dup, i);
	return (dup);
}
