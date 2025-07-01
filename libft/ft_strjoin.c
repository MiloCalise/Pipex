/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:57:05 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/21 14:32:13 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char const *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	dup = (char *)malloc(sizeof (char) * len + 1);
	if (!dup)
		return (NULL);
	dup[0] = '\0';
	ft_strcat(dup, s1);
	ft_strcat(dup, s2);
	return (dup);
}
