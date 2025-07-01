/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:36:51 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/05 15:39:22 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (s1[i] && s1[i] != (char)c)
		i++;
	if (s1[i] == (char)c)
		return (s1 + i);
	return (NULL);
}
