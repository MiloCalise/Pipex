/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:36:46 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/02 11:57:59 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	char	*dst;

	if (!dest && !src)
		return (NULL);
	tmp = (char *)src;
	dst = (char *)dest;
	if (tmp < dst)
	{
		tmp = tmp + n;
		dst = dst + n;
		while (n--)
			*--dst = *--tmp;
	}
	else
		ft_memcpy(dst, tmp, n);
	return (dest);
}
