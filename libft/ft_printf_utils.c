/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miltavar <miltavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:03:49 by miltavar          #+#    #+#             */
/*   Updated: 2025/05/21 14:37:40 by miltavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_calcu(long n)
{
	int				size;
	unsigned int	nb;

	size = 0;
	if (n == 0)
		return (++size);
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

void	fill_hex(char *dest, char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_put_unsigned_nbr(unsigned int nbr)
{
	if (nbr >= 10)
	{
		ft_put_unsigned_nbr(nbr / 10);
		ft_put_unsigned_nbr(nbr % 10);
	}
	else
		ft_putchar_fd(nbr + 48, 1);
}

int	ft_putnbr_hex_low(unsigned int nbr)
{
	char	hex[17];
	char	buffer[16];
	int		i;
	int		count;

	fill_hex(hex, "0123456789abcdef");
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	count = i;
	while (--i >= 0)
		ft_putchar_fd(buffer[i], 1);
	return (count);
}

int	ft_putnbr_hex_up(unsigned int nbr)
{
	char	hex[17];
	char	buffer[16];
	int		i;
	int		count;

	fill_hex(hex, "0123456789ABCDEF");
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	count = i;
	while (--i >= 0)
		ft_putchar_fd(buffer[i], 1);
	return (count);
}
