/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:28:08 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/05 17:19:15 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_calc(int n)
{
	size_t			size;
	unsigned int	nb;

	size = 0;
	if (n == 0)
		size++;
	if (n < 0)
	{
		nb = -n;
		size++;
	}
	else
		nb = n;
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static void	write_tab(char *str, int n, int size)
{
	size_t			i;
	unsigned int	nb;
	unsigned int	size_2;

	i = 0;
	size_2 = size - 1;
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	while (nb != 0)
	{
		str[size_2] = nb % 10 + 48;
		nb = nb / 10;
		size_2--;
	}
	str[size] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = size_calc(n);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	write_tab(str, n, size);
	return (str);
}
