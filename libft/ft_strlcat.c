/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:36:59 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/01 13:12:29 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	s_len = ft_strlen(src);
	while (dst[d_len] && d_len < size)
		d_len++;
	if (d_len == size)
		return (size + s_len);
	i = 0;
	while (src[i] && (d_len + i + 1) < size)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
