/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:10:42 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/02 11:57:01 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t n)
{
	unsigned char	*space;
	size_t			i;

	i = 0;
	space = (unsigned char *)s;
	while (i < n)
	{
		space[i] = 0;
		i++;
	}
}
