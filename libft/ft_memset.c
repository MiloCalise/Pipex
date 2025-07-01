/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:56:10 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/02 11:58:07 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*space;
	size_t			i;

	i = 0;
	space = (unsigned char *)s;
	while (i < n)
	{
		space[i] = c;
		i++;
	}
	return (space);
}
