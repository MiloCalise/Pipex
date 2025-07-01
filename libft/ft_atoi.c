/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:36:07 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/21 13:28:32 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

static int	calc_res(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (is_whitespace(nptr[i]) == 1)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = sign * -1;
		i++;
	}
	return (calc_res(nptr + i) * sign);
}
